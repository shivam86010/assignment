import React, { useState } from 'react'

function Component() {
    const [contactdata,setContactdata]=useState({
        name: "",
        email: ""
    });
    
    const handlinput=(event)=>{
        if(event.target.name==='name'){
            setContactdata({...contactdata, name : event.target.value})
        }
        else {
            setContactdata({...contactdata, email : event.target.value})
        }
    }
   
    const handleAdd=()=>{
        if(contactdata.name===" " || contactdata.email=== " "){
            alert("please fill contact information");
            return ;
        }
    }

  return (
    <div>
        <h1>Manage Contacts </h1>
        <form>
            <h2>Add Contact</h2>
            <label>Name :</label>
            <input type='text' placeholder='enter name..' value={contactdata.name} onChange={handlinput}/>
            <br/>
            <br/>
            <label>Email :</label>
            <input type='email' placeholder='enter email..' value={contactdata.email} onChange={handlinput}/>
            <br/>
            <br/>
        </form>
        <button onClick={handleAdd}>Add Contact</button>
    </div>
  )
}

export default Component