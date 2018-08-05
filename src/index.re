[@bs.module "./registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <App message="Welcome to React and Reason" />,
  "root",
);
/*
let render = (~domId, ~component, state, dispatch) => 
  component(state, dispatch)
    |> ReasonReact.element
    |> e => ReactDOMRe.renderToElementWithId(e, domId)

Store.subscribe (render ~domId="root" ~component=App)
*/
register_service_worker();
