// import { all } from 'axios';
// import React, { useState } from 'react'

// function Index() {
//     const [datalist, setDatalist]=useState('');
//     const [allList, setAllList]=useState([]);
//     const handleAddClick =()=>{
//         // e.preventdefault();
//         // setAllList([...allList, datalist]);
//         setAllList(()=>{
//             const updated=[...allList, datalist];
//             setDatalist("");
//             console.log("my all list is ", allList);
//             return updated;
//         })
        
//     }
//     const handleremove = (id)=>{
//         allList.filter((item, index)=>{
//            id!=index && return allList;
//         })
//     }
//   return (
//     <>
//         <div className='text-center item-center'>
//             <h1>Add Todo List</h1>
//             <div>
//                 <input 
//                 type='text' 
//                 value={datalist} 
//                 onChange={(e)=>setDatalist(e.target.value)}
//                 placeholder='enter todo list'
//                 className='border-2 border-gray-500 py-2 px-8'
//             />
//             <button onClick={handleAddClick} className='py-2 px-4 bg-green-400 rounded-md text-white font-semibold text-lg'>Add</button>
//             </div>
//             <div>
//                 {allList && 
//                     allList?.map((item, index)=>{
//                         return (
//                            <>
//                             <div key={index} className='flex flex-row item-center text-center'>
//                                 <p >{item}</p>
//                                 <button onClick={()=>handleremove(index)} className='bg-red-500 px-4 py-2 rounded-md text-white'>remove</button>
//                             </div>
//                            </>
//                         )
//                     })
//                 }
//             </div>
            
//         </div>
//     </>
//   )
// }

// export default Index
