import Data from './Data';
import Tour from './Tour';
import Cart from './Cart';
import './App.css';
import { useState } from 'react';

function App() {
   const[tourdata, setTourdat]=useState(Data)
  return (
      <> 
      <Tour tourdata={tourdata}/>
      </>
    
    );
}

export default App;
