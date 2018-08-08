[%raw "require('isomorphic-fetch')"]

let parseReposJson = json => json |> Json.Decode.array(Store.parseRepoJson);

let reposUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let fetchRepos = () =>
  Js.Promise.(
    Axios.get(reposUrl)
    |> then_((response) => resolve(Js.Result.Ok(parseReposJson(response##data##items))))
    |> catch((error) => resolve(Js.Result.Error(error)))
  );


exception Graphql_error(string);

let defaultHeaders = [%bs.raw {|
  {
    "Content-Type": "application/json",
    "X-Hasura-Access-Key": "mysecretkey"
  }
|}];

let headers =   Bs_fetch.HeadersInit.make(defaultHeaders);

let sendQuery = q =>
  Bs_fetch.(
    fetchWithInit(
      "http://localhost:8081/v1alpha1/graphql",
      RequestInit.make(
        ~method_=Post,
        ~body=
          Js.Dict.fromList([
            ("query", Js.Json.string(q##query)),
            ("variables", q##variables)
          ])
          |> Js.Json.object_
          |> Js.Json.stringify
          |> BodyInit.make,
        ~headers=headers,
        ()
      )
    )
    |> Js.Promise.then_(resp =>
          if (Response.ok(resp)) {
            Response.json(resp)
            |> Js.Promise.then_(data =>
                switch (Js.Json.decodeObject(data)) {
                | Some(obj) =>
                  Js.Dict.unsafeGet(obj, "data")
                  |> q##parse
                  |> Js.Promise.resolve
                | None =>
                  Js.Promise.reject(Graphql_error("Response is not an object"))
                }
              );
          } else {
            Js.Promise.reject(
              Graphql_error("Request failed: " ++ Response.statusText(resp))
            );
          }
        )
  );