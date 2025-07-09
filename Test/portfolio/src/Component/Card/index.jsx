// import React from 'react'
// import '../Card/CardCss/Card.css'

// function Index() {
//   return (
    
//     <div className="flip-card ">
//         <div className="flip-card-inner">
//             <div className="flip-card-front">
//                 <p className="title">FLIP CARD</p>
//                 <p>Hover Me</p>
//             </div>
//             <div className="flip-card-back">
//                 <p className="title">BACK</p>
//                 <p>Leave Me</p>
//             </div>
//         </div>
//     </div>
    
//   )
// }

// export default Index

import React from 'react';
import '../Card/CardCss/Card.css';

function Card({ width = '300px', height = '400px' }) {
  const cardStyle = {
    width,
    height,
  };

  return (
    <div className="flip-card" style={cardStyle}>
      <div className="flip-card-inner">
        <div className="flip-card-front">
          <p className="title">FLIP CARD</p>
          <p>Hover Me</p>
        </div>
        <div className="flip-card-back">
          <p className="title">BACK</p>
          <p>Leave Me</p>
        </div>
      </div>
    </div>
  );
}

export default Card;

