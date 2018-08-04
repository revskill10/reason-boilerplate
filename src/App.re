[%bs.raw {|require('./styles/App.css')|}];

type state = { repoData : option(array(RepoData.repo)) }; 
  
type event = 
  | Loaded(array(RepoData.repo));

let dummyRepos: array(RepoData.repo) = [|
  {
    stargazers_count: 27,
    full_name: "jsdf/reason-react-hacker-news",
    html_url: "https://github.com/jsdf/reason-react-hacker-news"
  }, 
  {
    stargazers_count: 27,
    full_name: "jsdf1reason-react-hacker-news",
    html_url: "https://github.com/jsdf/reason-react-hacker-news"
  }, 
|];

let initialState = () => { repoData : None }; 

let component = ReasonReact.reducerComponent("App");

let createRepoItem = repoData => <RepoItem repo=repoData />;

let loadReposButton = send =>
  <button onClick=(_event => send(Loaded(dummyRepos)))>
    {ReasonReact.string("Load Repos")}
  </button>;

let createRepoItems = (repoItems, send) =>
  switch repoItems {
    | Some(repos) => ReasonReact.array(Array.map(createRepoItem, repos))
    | None => loadReposButton(send)
  };

let reducer = (event, state) =>
  switch event {
  | Loaded(loadedRepos) => ReasonReact.Update({ repoData: Some(loadedRepos) })
  };

let render1 = (repoData, send) =>
  <div className="App">
    <div className="App-header">
      <TopBar />
      (ReasonReact.string("hehe"))
    </div>   
    (createRepoItems(repoData, send))
  </div>

let make = (~message, _children) => {
  ...component,
  initialState,
  reducer,
  render: ({state, handle, send}) => 
    render1(state.repoData, send)
};
