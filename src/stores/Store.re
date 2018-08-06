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

type event = 
  | CounterEvent(CounterStore.event)

type state = {
  counter: CounterStore.state
};

let initialState : state = {
  counter: CounterStore.initialState
}

type store = {
  state,
  publish: event => unit
};

let component = ReasonReact.reducerComponent("Store");

let make = (~render, _children) => {
  ...component,
  initialState: () => initialState,
  reducer: (event : event, state : state) =>
    switch event {
    | CounterEvent(e) => ReasonReact.Update({ counter: CounterStore.fold(e, state.counter) })
    },
  render: self =>
    render({state: self.state, publish: event => self.send(event)})
};