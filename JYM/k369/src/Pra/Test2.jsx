// import React, { useState } from 'react'

// function Test2() {
//     const [box, setBox]=useState(Array(9).fill(null))
//     const [xTurn, setXTurn]=useState(true);
//     const [winner, setWinner]=useState(null);
//     const createSquare = (index)=>{
//         return (
//             <>
//             <button onClick={()=>handleBoard(index)}  className='border-2 border-gray-400 font-bold text-xl px-4 py-2'>{box[index]}</button>
//             </>
//         )
//     }

//     const handleBoard = (index)=>{
//         console.log("my index", index);
//         const newbox=[...box];
//         newbox[index]=xTurn ? 'x' : '0';
//         setBox(newbox)
//         setXTurn(!xTurn);
//         const winnercomb= checkwinner(newbox);
//         if(winnercomb)
//         {
//             setWinner(newbox[winnercomb[0]]);
//         }
//     }
   

//     const checkwinner = (box)=>{
//         const combination = [
//             [0, 1, 2],
//             [3 ,4, 5],
//             [6, 7, 8],
//             [0, 3, 6],
//             [1, 4, 7],
//             [2, 5, 8],
//             [0, 4, 8],
//             [2, 4, 6],
//         ]

//         for(let i=0; i<combination.length; i++)
//         {
//             const [a, b, c]=combination[i];
//             if(box[a] === box[b] && box[b] === box[c])
//             {
//                 return combination[i];
//             }
//         }
//         return null;
//     }
//   return (
//     <div>
//       <h1>Tic Tok </h1>
//       <div className='flex flex-col gap-2 ' >
//         <div className='gap-2 flex'>
//             {createSquare(0)}
//             {createSquare(1)}
//             {createSquare(2)}
//         </div>
//         <div className='flex gap-2'>
//             {createSquare(3)}
//             {createSquare(4)}
//             {createSquare(5)}
//         </div>
//         <div className='flex gap-2'>
//             {createSquare(6)}
//             {createSquare(7)}
//             {createSquare(8)}
//         </div>
//       </div>

//       {winner && <div>{winner} is winner of this game </div>}
//     </div>
//   )
// }

// export default Test2

import React, { useState } from 'react'

function Test2() {
    const [box, setBox]=useState(Array(9).fill(null));
    const [xTurn, setXTurn]=useState(true);
    const [winner, setWinner]=useState(null);

    const makeSquare = (index)=>{
        return (
            <>
            <button onClick={()=>handleClick(index)} className='border-2 border-gray-400 px-6 py-4'>{box[index]}</button>
            </>
        )
    }
 console.log("my winner is ", winner)
    const handleClick = (index)=>{
        console.log("my index", index)
        const newbox=[...box];
        newbox[index]= xTurn ? 'X' : '0';
        setBox(newbox);
        setXTurn(!xTurn);

        const winnercomb = checkwinner(newbox);
        if(winnercomb)
        {
            setWinner(newbox[winnercomb[0]]);
        }
    }

    const checkwinner =(box)=>{
        const combination =[
            [0, 1, 2],
            [3, 4, 5],
            [6, 7, 8],
            [0, 3, 6],
            [1, 4, 7],
            [2, 5, 8],
            [0, 4, 8],
            [2, 4, 6]
        ]

        for(let i=0; i<combination.length; i++)
        {
            const [a, b, c]=combination[i];
            if(box[a] === box[b] && box[b] === box[c])
            {
                return combination[i];
            }
        }
        return null;
    }
  return (
    <div className='flex flex-col text-center item-center'>
        <h1>tic Tok game</h1>
      <div className='flex flex-col gap-2 '>
        <div className='flex gap-2'>
            {makeSquare(0)}
            {makeSquare(1)}
            {makeSquare(2)}
        </div>
        <div className='flex gap-2'>
            {makeSquare(3)}
            {makeSquare(4)}
            {makeSquare(5)}
        </div>
        <div className='flex gap-2'> 
            {makeSquare(6)}
            {makeSquare(7)}
            {makeSquare(8)}
        </div>
      </div>
      {winner && <div>{winner} is winner of this game </div> }
    </div>
  )
}

export default Test2

