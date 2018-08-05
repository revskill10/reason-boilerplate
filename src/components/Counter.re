let component = ReasonReact.statelessComponent("Counter");

let make = (~store: Store.store, _children) => {
  ...component,
  render: _self => 
    <div>
      <span>
        (
          ReasonReact.string(
            "Count: " ++ string_of_int(store.state.counter.count)
          )
        )
      </span>
      <br />
      <button>
        (ReasonReact.string(Eng.increment_label))
      </button>
      <button>
        (ReasonReact.string(Eng.decrement_label))
      </button>
    </div>
}
