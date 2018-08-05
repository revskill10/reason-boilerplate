let component = ReasonReact.statelessComponent("Error")

let make = (~error, _children) => {
  ...component,
  render: (_self) => switch (error) {
  | None => <div />
  | Some(err) => <div>(ReasonReact.string(err))</div>
  }
}