import React from 'react';
import './App.css';
import openSocket from 'socket.io-client';

const  socket = openSocket('http://localhost:8080');

class App extends  React.Component 
{
  constructor(props) {
    super(props);
    this.state = {
      data : [],
      isLoaded : false,
    }
  }

componentDidMount(){
    fetch('https://jsonplaceholder.typicode.com/users')
    //  fetch('https://webhook.site/87852ebd-d21a-41c3-a6da-0bd17592f519')
        .then(res => res.json())
        .then(json => {
            this.setState({
                isLoaded: true,
                data: json,
            })
        });
  }

render() {

    var {isLoaded, data} = this.state;
    if (!isLoaded)
    return(<div className = "App">loading..!</div>);
  else {
  return (
    <div className="App">
          <ol> {data.map(temp => (
                <li key = {temp.id }> {temp.name} : {temp.email} </li>
           ))}
          </ol>
    </div>
  );
}
}
}
export default App;
