import React, { useState } from 'react'

function Component() {
const[board, setBoard]=useState(Array(9).fill(null));
const[xturn,setXturn]=useState(true);
const [winner, setWinner]=useState(null);

    const makebutton=(index)=>{
        return(
            <button className='square' onClick={()=>handleClick(index)}>{board[index]}</button>
        )
    }
    const handleClick=(index)=>{
        if(board[index]!=null)
        return;

        const newBoard =[...board];
        newBoard[index] =xturn ? 'X' : 'O';
        setBoard(newBoard);
        setXturn(!xturn);
        const winnercombination= checkwinner(newBoard);
        if(winnercombination){
            setWinner(newBoard[winnercombination[0]]);
        }
    }
    const checkwinner=(newBoard)=>{
        const combination=[
            [0,1,2],[3,4,5],[6,7,8],
            [0,3,6],[1,4,7],[2,5,8],
            [0,4,8],[2,4,6],
        ];
        for(let i=0; i<combination.length; i++){
            const[a,b,c]=combination[i];
            if(newBoard[a] && newBoard[a]===newBoard[b] && newBoard[b]===newBoard[c]){
                return combination[i];
            }
        }
        return null
    };

    const resethandle=()=>{
        setBoard(Array(9).fill(null));
        setWinner(null);
    }
  return (
    <>
    <div className='board'>
        <div className='board-row'>
            {makebutton(0)}
            {makebutton(1)}
            {makebutton(2)}
        </div>
        <div className='board-row'>
            {makebutton(3)}
            {makebutton(4)}
            {makebutton(5)}
        </div>
        <div className='board-row'>
            {makebutton(6)}
            {makebutton(7)}
            {makebutton(8)}
        </div>
    
    </div>
    <button onClick={resethandle} className='buttonset'>Reset</button>
    {winner && <div>{winner }is winner of this game</div>}
    </>
  )
}

export default Component