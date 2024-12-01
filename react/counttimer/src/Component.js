import React, { useEffect, useRef, useState } from 'react'

function Component() {
    const[time, setTime]=useState(0);
    const [isactive, setActive]=useState(false);
    const [ispused, setPused] =useState(false);
    let userefele=useRef(null);

    const handleinput=(event)=>{
        setTime(parseInt(event.target.value*60));
    }
    const formattimer=()=>{
        const min=String(Math.floor(time/60)).padStart(2, '0');
        const sec=String(time%60).padStart(2, '0');
        return `${min} : ${sec}`
    }

    const handlestart=()=>{
        setActive(true);
        setPused(false);
    }
    useEffect( ()=>{
        if(isactive && !ispused && time>0){
            userefele.current=setInterval(() => {
                setTime((pre)=>pre-1)
            }, 1000);
        }
        else if(time===0){
            clearInterval(userefele.current);
            setActive(false);
            alert("your time is up");
        }
        return ()=>clearInterval(userefele.current);
    }, [isactive, ispused, time]);

    const handlepused=()=>{
        setPused(!ispused);
    }

    const handlerestart=()=>{
       clearInterval(userefele.current);
       setActive(false);
       setPused(false);
       setTime(0);
    }
  return (
    <>
    <h1>countdown timer</h1>
    <div>
        <input type='number' placeholder='enter the time in min..' onChange={handleinput}/>
        <div>{formattimer()}</div>
        <div className='btn'>
            <button onClick={handlestart} disabled={isactive && !ispused}>start</button>
            <button onClick={handlepused} disabled={!isactive}>{ispused ? "Resume" : "pused"}</button>
            <button onClick={handlerestart}>restart</button>
        </div>
    </div>
    </>
  )
}

export default Component