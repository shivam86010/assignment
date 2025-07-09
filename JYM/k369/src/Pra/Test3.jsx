// import React, { useState, useEffect } from 'react';

// const getInitialTodos = () => {
//   const stored = localStorage.getItem('todos');
//   try {
//     return stored ? JSON.parse(stored) : [];
//   } catch (e) {
//     console.error("Failed to parse todos:", e);
//     return [];
//   }
// };

// const TodoApp = () => {
//   const [task, setTask] = useState('');
//   const [todos, setTodos] = useState(getInitialTodos); // ✅ Load from localStorage initially
//   const [isEditing, setIsEditing] = useState(false);
//   const [currentId, setCurrentId] = useState(null);

//   // Save to localStorage when todos change
//   useEffect(() => {
//     localStorage.setItem('todos', JSON.stringify(todos));
//   }, [todos]);

//   const handleAddOrUpdate = () => {
//     if (task.trim() === '') return;

//     if (isEditing) {
//       const updated = todos.map((todo) =>
//         todo.id === currentId ? { ...todo, text: task.trim() } : todo
//       );
//       setTodos(updated);
//       setIsEditing(false);
//       setCurrentId(null);
//     } else {
//       const newTodo = {
//         id: Date.now(),
//         text: task.trim(),
//       };
//       setTodos([...todos, newTodo]);
//     }

//     setTask('');
//   };

//   const handleEdit = (todo) => {
//     setTask(todo.text);
//     setIsEditing(true);
//     setCurrentId(todo.id);
//   };

//   const handleDelete = (id) => {
//     const filtered = todos.filter((todo) => todo.id !== id);
//     setTodos(filtered);
//   };

//   return (
//     <div style={{ maxWidth: '400px', margin: '50px auto', textAlign: 'center' }}>
//       <h2>📝 To-Do List</h2>
//       <input
//         type="text"
//         placeholder="Enter task..."
//         value={task}
//         onChange={(e) => setTask(e.target.value)}
//         style={{ padding: '10px', width: '70%' }}
//       />
//       <button
//         onClick={handleAddOrUpdate}
//         style={{
//           padding: '10px',
//           marginLeft: '10px',
//           backgroundColor: isEditing ? '#f0ad4e' : '#28a745',
//           color: 'white',
//           border: 'none',
//           cursor: 'pointer',
//         }}
//       >
//         {isEditing ? 'Update' : 'Add'}
//       </button>

//       <ul style={{ listStyle: 'none', padding: 0, marginTop: '20px' }}>
//         {todos.map((todo) => (
//           <li
//             key={todo.id}
//             style={{
//               padding: '10px',
//               borderBottom: '1px solid #ccc',
//               display: 'flex',
//               justifyContent: 'space-between',
//               alignItems: 'center',
//             }}
//           >
//             <span>{todo.text}</span>
//             <div>
//               <button
//                 onClick={() => handleEdit(todo)}
//                 style={{
//                   background: '#ffc107',
//                   color: 'white',
//                   border: 'none',
//                   padding: '5px 10px',
//                   marginRight: '5px',
//                   cursor: 'pointer',
//                 }}
//               >
//                 Edit
//               </button>
//               <button
//                 onClick={() => handleDelete(todo.id)}
//                 className='bg-red-500'
//               >
//                 Delete
//               </button>
//             </div>
//           </li>
//         ))}
//       </ul>
//     </div>
//   );
// };

// export default TodoApp;

import React, { useEffect, useState } from 'react'
const getFromLocalstorage= ()=>{
  const store=localStorage.getItem('todos');
  try {
    return store ? JSON.parse(store) : [];
  } catch (error) {
    console.log("my error", error);
    return [];
  }
}
function Test3() {
  const [task, setTask]=useState('');
  const [alltask, setAllTask]=useState(getFromLocalstorage);
  const [isEditing, setIsEditing]=useState(false);
  const [currentId, setCurrentId]=useState(null);

  useEffect(()=>{
     localStorage.setItem('todos', JSON.stringify(alltask));
  }, [alltask])

  const handleAddClick = ()=>{
    if(task.trim() === '')
      return ;

    if(isEditing)
    {
       const update = alltask.map((item)=>

      item.id===currentId ? {...item, text : task.trimEnd()} : item
       );
       setAllTask(update);
       setIsEditing(false);
       setCurrentId(null);
    }
    else{
      const newtask={
        id : Date.now(),
        text : task.trim(),
      };
      setAllTask([...alltask, newtask]);
    }

    setTask('');
  }
  const handleEdit = (task)=>{
    setTask(task.text);
    setIsEditing(true);
    setCurrentId(task.id);
  }


  return (
    <div>
      <h1>add todo </h1>
      <div className='flex'>
        <div className='flex flex-col'>
          <lable>Enter Task</lable>
          <input 
            type='text'
            value={task}
            onChange={(e)=>setTask(e.target.value)}
            className='border-2 border-gray-400'
          />
        </div>
        <button onClick={handleAddClick}>Add</button>
      </div>
      <div>
        {alltask.map((item)=>(
          <div key={item.id}>
            <div className='flex gap-2'>
              <p>{item.text}</p>
              <button>delete</button>
              <button>edit</button>
            </div>
          </div>
        ))}
      </div>
    </div>
  )
}

export default Test3

