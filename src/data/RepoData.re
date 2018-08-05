type repo = {
    full_name: string,
    stargazers_count: int,
    html_url: string
  };



let parseRepoJson = (json: Js.Json.t) : repo =>
  Json.Decode.{
    full_name: json |> field("full_name", string),
    stargazers_count: json |> field("stargazers_count", int),
    html_url: json |> field("html_url", string)
  };


