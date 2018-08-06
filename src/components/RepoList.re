let component = ReasonReact.statelessComponent("RepoList")

let currentCount = (store : Events.store) => string_of_int(store.state.counter.count);

let make = (~store: Store.store, _children) => {
  ...component,

  render: _self => 
    <div>
      <span>
        <String value=(currentCount(store)) />
      </span>
      <br />
    </div>
  }