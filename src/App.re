[%bs.raw {|require('./styles/App.css')|}];

type state = { 
  repoData : option(array(Store.repo)), 
  error: option(string) 
}; 
/*
type event = 
  | Loaded(array(RepoData.repo))
  | Request
  | NetworkError(string);
*/
let initialState = () => { 
  repoData : None, 
  error : None
}; 

let component = ReasonReact.reducerComponent("App");

let createRepoItem = (i, repoData) => <RepoItem key={string_of_int(i)} repo=repoData />;

let loadReposButton = send =>
  <button onClick=(_event => send(`Request))>
    {ReasonReact.string("Load Repos")}
  </button>;

let createRepoItems = (repoItems, send) =>
  switch repoItems {
    | Some(repos) => ReasonReact.array(Array.mapi(createRepoItem, repos))
    | None => loadReposButton(send)
  };

let resolve = (send) =>
  Js.Promise.then_(
    (res) => 
      switch res {
      | Js.Result.Ok(repos) => { send(`Loaded(repos)); Js.Promise.resolve(); }
      | Js.Result.Error(_err) => { send(`NetworkError("Error")); Js.Promise.resolve(); }
      }
  ) 

let reducer = (event, state) =>
  switch event {  
  | `Request => ReasonReact.SideEffects(
      self => {
        Api.fetchRepos()
        |> resolve(self.send)
        |> ignore;
      })
  | `Loaded(loadedRepos) => ReasonReact.Update({ ...state, repoData: Some(loadedRepos) })
  | `NetworkError(err) => ReasonReact.Update({ ...state, error: Some(err) })
  };

let render = (~repoData, ~error, ~send) =>
  <div className="App">
    <div className="App-header">
      <TopBar />
      (ReasonReact.string("hehe"))
    </div>   
    (createRepoItems(repoData, send))
    <div className="App-error">
      <Error error=error />
    </div>
  </div>


let make = (~message, _children) => {
  ...component,
  initialState,
  reducer,
  render: ({state, handle, send}) => 
    render(state.repoData, state.error, send)
};
