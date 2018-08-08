module HeroQuery = [%graphql {|
  {
    messages(limit: 50){
      data
    }
  }
|}];

module UserQuery = [%graphql {|
  {
    users(limit:50) {
      email
      password
    }
  }
|}];