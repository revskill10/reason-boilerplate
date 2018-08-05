let parseReposJson = json => json |> Json.Decode.array(RepoData.parseRepoJson);

let reposUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let fetchRepos = () =>
  Js.Promise.(
    Axios.get(reposUrl)
    |> then_((response) => resolve(Js.Result.Ok(parseReposJson(response##data##items))))
    |> catch((error) => resolve(Js.Result.Error(error)))
  );
