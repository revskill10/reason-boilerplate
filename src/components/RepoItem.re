let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repo: Store.repo, _children) =>
  {
    ...component,
    render: (_self) =>
      <div>{ReasonReact.string(repo.full_name)}</div>
  };