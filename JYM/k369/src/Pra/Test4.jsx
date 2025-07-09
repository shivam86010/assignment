// import React, { useEffect, useState } from 'react'

// function Test4() {
//   const [box, setBox]=useState(Array(9).fill(null));
//   const [xTurn, setXTurn]=useState(true);
//   const [winner, setWinner]=useState(false);

//   const createSquare = (index) =>{
//     return (
//       <>
//       <button onClick={()=>handleClick(index)} className='px-6 py-4  bg-green-400'>{box[index]}</button>
//       </>
//     )
//   }

//   const handleClick = (index)=>{

//     if(winner || box[index])
//       return ;

//     const newbox=[...box];
//     newbox[index]=xTurn ? 'X' : 'O';
//     setBox(newbox);
//     setXTurn(!xTurn)

//     const winnerans=handleWinner(newbox);
//     if(winnerans)
//     {
//        setWinner(newbox[winnerans[0]]);
//     }
//   }

//   useEffect(()=>{
//     console.log("my winner is ", winner);
//   }, [winner])
   
//   const handleWinner= (box)=>{
//     const combination = [
//       [0, 1 ,2],
//       [3, 4, 5],
//       [6, 7, 8],
//       [0, 3, 6],
//       [1, 4, 7],
//       [2, 5, 8],
//       [0, 4, 8],
//       [2, 4, 6],
//     ]

//     for(let i=0; i<combination.length; i++)
//     {
//       const [a, b, c]=combination[i];
//       if(box[a] && box[a]=== box[b] && box[b]===box[c])
//       {
//         return combination[i];
//       }
//     }
//     return null;
//   }

//   const handleReset = ()=>{
//     setBox(Array(9).fill(null));
//     setXTurn(true);
//     setWinner(false);
//   }

//   return (
//     <div>
//       <h1 className='text-xl font-semibold'>Tic Toc Game</h1>
//       <div className='flex flex-col gap-2'>
//         <div className='flex gap-2'>
//           {createSquare(0)}
//           {createSquare(1)}
//           {createSquare(2)}
//         </div>
//         <div className='flex gap-2'>
//           {createSquare(3)}
//           {createSquare(4)}
//           {createSquare(5)}
//         </div>
//         <div className='flex gap-2'>
//           {createSquare(6)}
//           {createSquare(7)}
//           {createSquare(8)}
//         </div>
//       </div>

//       {winner && <p>{winner} is winner of this game</p>}
      
//       {winner && 
//       <button onClick={handleReset} >Reset</button>
//       }
//     </div>
//   )
// }

// export default Test4



// import React, { useEffect, useRef, useState } from 'react'

// function Test4() {
//   const [time, setTime]=useState(0);
//   const [isActive, setIsActive]=useState(false);
//   const [isPaused, setIsPaused]=useState(false);
//   const intervalRef=useRef();

//   const handleClick = (e)=>{
//     setTime(parseInt(e.target.value*60))
//   }
//   const formatTime = ()=>{
//     const min=String(Math.floor(time/60)).padStart(2, '0');
//     const sec= String((time%60)).padStart(2, '0');
//     return `${min} : ${sec}`
//   }

//   const handleStartClick = ()=>{
//      setIsActive(true);
//      setIsPaused(false);
//   }

//   useEffect(()=>{
//     if(isActive && time>0 && !isPaused)
//     {
//        intervalRef.current=setInterval(() => {
//         setTime((prev)=>prev-1);
//        }, 1000);
//     }
//     else if(time==0)
//     {
//       clearInterval(intervalRef.current);
//       setIsActive(false);
//     }

//     return ()=>clearInterval(intervalRef.current);
//   }, [isActive, time, isPaused])

//   const handlePaused = ()=>{
//     setIsPaused(!isPaused);
//   }
//     const handleReset = () => {
//     clearInterval(intervalRef.current);
//     setIsActive(false);
//     setIsPaused(false);
//     setTime(0);
//   };
//   return (
//     <div>
//       <h1>Count Down Timer</h1>
//       <div>
//         <input type='number' 
//             min={0}
//             // value={time}
//             onChange={handleClick}
//             className='border-2 border-gray-400'
//         />

//         <div>{formatTime() }</div>
//       </div>
//       <div className='flex gap-4'>
//     <button
//   disabled={isActive && !isPaused}
//   onClick={handleStartClick}
//   className={`rounded-md px-4 py-2 text-white ${
//     isActive && !isPaused ? 'bg-gray-400 cursor-not-allowed' : 'bg-green-500 hover:bg-green-600'
//   }`}
// >
//   Start
// </button>
//         <button
//   onClick={handlePaused}
//   disabled={!isActive}
//   className={`rounded-md px-4 py-2 text-white ${
//     !isActive ? 'bg-gray-400 cursor-not-allowed' : 'bg-yellow-500 hover:bg-yellow-600'
//   }`}
// >
//   {isPaused ? 'Resume' : 'Pause'}
// </button>

// <button
//   onClick={handleReset}
//   className='bg-red-500 hover:bg-red-600 rounded-md px-4 py-2 text-white'
// >
//   Reset
// </button>

//       </div>
//     </div>
//   )
// }

// export default Test4

import React, { useEffect, useState } from 'react'

const Test4 = () => {
  const [text, setText]=useState([]);
  useEffect(()=>{
    localStorage.setItem(JSON.stringify('todos', text));
  }, [text])
  const handleClick = ()=>{
    const newText =[...text];
    setText(newText);
  }

  return (
    <div>
      <h1>Todo List</h1>
      <div>
        <div className='flex gap-2'>
          <input  type='text'
            value={text}
            onChange={(e)=>setText(e.target.value)}
            className='border border-gray-400 py-2'  
          />
          <button onClick={handleClick} className='bg-green-400 py-2 px-4 rounded-md'>Add Todo</button>
        </div>
      </div>

      {
        text?.map((item, index)=>(
          <div>
            <p>{item}</p>
          </div>
        ))
      }
    </div>
  )
}

export default Test4


