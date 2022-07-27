import logo from './logo.svg';
import './App.css';
import Navbar from './Navbar'
import Home from './Home';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom'
import About from './About';

function App() {
  const title = "haseeb is here which is why this is printed";
  const likes = 90;
  const person = {
    namaewa: "haseeb",
    age: 30
  };
  const link = "https://www.google.com"

  return (
    <Router>
      <div className="App">
        <Navbar />
        <div className="content">
          <Switch>
            <Route exact path="/">
              <Home/>
            </Route>
            <Route path ="/About">
              <About/>
            </Route>
          </Switch>
        </div>
      </div>
    </Router>
  );

}

export default App;
