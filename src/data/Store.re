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

module Counter = {
  type event =
  | Increased
  | Decreased;

  type state = {
    count: int
  };

  let initialState = {
    count: 0
  }

  let fold = (event: event, state: state) => 
    switch event {
    | Increased =>  { count : state.count + 1 }
    | Decreased =>  { count : state.count - 1 }
    };
};

type event = 
  | Counter(Counter.event)

type state = {
  counter: Counter.state
};

let initialState = {
  counter: Counter.initialState
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
    | Counter(e) => ReasonReact.Update({ counter: Counter.fold(e, state.counter) })
    },
  render: self =>
    render({state: self.state, publish: event => self.send(event)})
};