let component = ReasonReact.statelessComponent("String");

let make = (~value: string, _children) => {
  ...component,

  render: _self => 
    (ReasonReact.string(value))
}