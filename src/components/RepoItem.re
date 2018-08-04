let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repo: RepoData.repo, _children) =>
  {
    ...component,
    render: (_self) =>
      <div>{ReasonReact.string(repo.full_name)}</div>
  };