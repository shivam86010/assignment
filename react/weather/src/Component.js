
import axios from 'axios';
import React, { useState } from 'react';

function Component() {
    const [city, setCity] = useState();
    const [weathers, setWeather]=useState();

    const handleinput=(event)=>{
        setCity(event.target.value);
    }
    const fethchdata=async ()=>{
        try{
            const response=await axios.get(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${'9ae2200eb82722e0ffc52f3ea098a71'}`)
            setWeather(response);
        }
        catch(error){
           console.log("error in fetchin g in data" , error);
        }
    }
    const handledata=()=>{
        fethchdata();
    }
    return(
    <>
    <h1>Weather App</h1>
    <div>
        <input type='text' placeholder='enter city..' value={city} onChange={handleinput}/>
        <p>{city}</p>
        <button onClick={handledata}>Get Wether</button>
        <div>
            <h2>{weathers.data.name}</h2>
        </div>
    </div>
    
    </>
  )
}

export default Component