let component = ReasonReact.statelessComponent("Counter");


let add = (x: int, y: int) => x + y;

let increase = (store : Events.store, _event) => {
  JsUtils.log("increasing");
  JsUtils.alert("Hello World");
  store.publish(Events.counterIncreased);
};

let decrease = (store : Events.store, _event) => {
  JsUtils.log("decrease");
  store.publish(Events.counterDecreased);
};

let make = (~store: Events.store, _children) => {
  ...component,

  render: _self => 
    <div>
      <h1> (ReasonReact.string("Hello")) </h1>
      <span>
        <RepoList store />
      </span>
      <br />
      <button onClick=(increase(store))><String value=(Eng.increment_label) /></button>
      <button onClick=(decrease(store))><String value=(Eng.decrement_label) /></button>
      <App message="Lol" />
    </div>
  }
