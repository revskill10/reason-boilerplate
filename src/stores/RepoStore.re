type event =
  | Increased
  | Decreased;
/*
type state = {
  repoData : option(array(Store.repo)), 
  error: option(string) 
};

let initialState : state = {
  count: 0
}

let fold = (event: event, state: state) => 
  switch event {
  | Increased =>  { count : state.count + 1 }
  | Decreased =>  { count : state.count - 1 }
};
*/