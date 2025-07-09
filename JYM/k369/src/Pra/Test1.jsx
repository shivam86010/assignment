import React, { useEffect, useRef, useState } from 'react'

function Test1() {
    const [time, setTime]=useState(0);
    const handleChange = (e)=>{
        setTime(parseInt(e.target.value*60));
    }

    const [isActive, setIsActive]=useState(false);
    const [isPaused, setIsPaused]=useState(false)
    const intervalRef=useRef();

    const formatTime = ()=>{
        const min=String(Math.floor(time/60)).padStart(2, '0');
        const sec=String(time%60).padStart(2,'0');
        return `${min} : ${sec}`
    }

    const handleStart = ()=>{
        setIsActive(true);
        setIsPaused(false)
    }

    useEffect(()=>{
        if(isActive && !isPaused && time>0)
        {
            intervalRef.current=setInterval(()=>{
                setTime((prev)=>prev-1)
            }, 1000);
        }
        else if(time==0)
        {
            clearInterval(intervalRef.current);
            setIsActive(false);
            // alert('time is up');
        }

        return ()=>clearInterval(intervalRef.current);
    }, [isActive, isPaused, time])

    const handlePaused = ()=>{
        
        setIsPaused(!isPaused);
    }

    const handleReset = ()=>{
        clearInterval(intervalRef.current);
        setIsActive(false);
        setIsPaused(false);
        setTime(0);
    }
  return (
    <div>
      <h1 className='bg-red-500'>count down timer</h1>
      <div>
        <input 
            type='number' 
            onChange={handleChange}
            min={0}
            className='border-2 border-gray-500'
            
        />
        <div>{formatTime()}</div>
      </div>
      
      <div className='flex gap-4'>
        <button 
            onClick={handleStart}
            disabled={isActive && !isPaused}
            className='bg-green-500 px-4 py-2 rounded-md text-white font-semibold'
        >start</button>
        <button 
        onClick={handlePaused}
        disabled={!isActive}
          className='bg-black px-4 py-2 rounded-md text-white font-semibold'>{isPaused ? "resume" : "paused"}</button>
        <button 
        onClick={handleReset}
        className='bg-red-500 px-4 py-2 rounded-md text-white font-semibold'>Reset</button>
      </div>
    </div>
  )
}

export default Test1
