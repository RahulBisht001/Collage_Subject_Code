import logo from "./logo.svg";
import "./App.css";
import StudentName from "./components/StudentName";

function App() {
    let stdName = "Ram";
    return (
        <div className="App">
            <img src={logo} className="App-logo" alt="logo" />

            <h1>Rahul B</h1>
            <a href="https://rahulbisht.com">www.rahulbisht.com</a>

            <StudentName stdName={stdName} />
        </div>
    );
}

export default App;
