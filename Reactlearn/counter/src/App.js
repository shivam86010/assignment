import { useState } from 'react';
import './App.css';

function App() {
  const [count, setCount]=useState(0);
  function increasecount()
  { 
    if(count<20)
    setCount(count+1);
  }
  function decrementcount()
  {
    if(count>0)
    setCount(count-1);
  }
  function resetcount()
  {
    setCount(0);
  }
  return (
    <div className="App">
      
      <h1>Happy diwali counter </h1>
      <div className='bodyofcounter'>

      <button onClick={increasecount}>+</button>
      <button>{count}</button>
    
      <button onClick={decrementcount}>-</button>
      <div className='reset-container'>
       <button onClick={resetcount}>reset</button> 
       </div>
      </div>
    </div>
  );
}

export default App;
