let component = ReasonReact.statelessComponent("TopBar");

let str = ReasonReact.string;

let make = (_children) => {
  ...component, 
  
  render: (_self) => 
    <header> 
      <a href="#"> (str("Logo")) </a>
      <span> (str("Super Marvel Heroes")) </span>
      <input placeholder="search 1" />
      <button> (str("Search")) </button>
    </header>
};
