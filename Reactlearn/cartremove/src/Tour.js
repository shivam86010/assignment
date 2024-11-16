import React from 'react'
import Cart from './Cart'

function Tour({tourdata}) {
  return (
    <div>
        <div>
            <h1>Happy Diwali</h1>
        </div>
        
        <div>
            {
                tourdata.map((tour)=>{
                    return <Cart {...tour}/>
                })
            }
        </div>

    </div>
  )
}

export default Tour