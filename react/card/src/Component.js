import React, { useState } from 'react'

function Component() {
    const[islogin, setLogin]=useState(true);
  return (
    <div className='container'>
        <div className='form-container'>
            <div className='form-toggle'>
                <button className={islogin ? 'active' : " "} onClick={()=>setLogin(true)}>Login</button>
                <button className={!islogin ? 'active' : " "} onClick={()=>setLogin(false)}>sign up</button>
            </div>
            {islogin ?<>
            <div className='form'>
                <h2>Login</h2>
                <input type='text' placeholder='email....'/>
                <input type='password' placeholder='password...'/>
                <a href='#'>forget password ?</a>
                <button>Login</button>
                <p>not a member <a href='#'  onClick={()=>setLogin(false)}>sign up</a></p>
            </div>
            </>
            : <>
            <div className='form'>
                <h2>sign up</h2>
                <input type='text' placeholder='email....'/>
                <input type='password' placeholder='password...'/>
                <input type='password' placeholder='confirm password..'/>
                <button>sign up</button>
            </div>
            </>}
        </div>
    </div>
  )
}

export default Component