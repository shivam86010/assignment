// import React from "react";

// export default function ProductCard({ title, price, oldPrice, discount, image }) {
//   return (
//     <div className="bg-white rounded-xl shadow hover:shadow-lg overflow-hidden transition duration-300">
//       <img src={image} alt={title} className="w-full h-60 object-cover" />
//       <div className="p-4">
//         <h4 className="text-sm font-semibold text-gray-600">3D Model</h4>
//         <p className="text-gray-900 font-medium">{title}</p>
//         <div className="flex items-center space-x-2 mt-2">
//           <span className="text-[#006483] font-semibold">Rs.{price}</span>
//           {oldPrice && (
//             <span className="line-through text-gray-400 text-sm">Rs.{oldPrice}</span>
//           )}
//           {discount && (
//             <span className="text-sm text-[#006483] font-semibold">({discount})</span>
//           )}
//         </div>
//         <p className="text-gray-400 text-xs mt-1">max, obj, fbx, 3ds, lwo and more</p>
//       </div>
//     </div>
//   );
// }

import React from "react";
import { FaHeart } from "react-icons/fa";

export default function ProductCard({ title, price, oldPrice, discount, image }) {
  return (
    <div className="relative bg-white rounded-xl shadow hover:shadow-lg overflow-hidden transition duration-300">
      {/* Love Icon */}
      <div className="absolute top-3 right-3 bg-white p-2 rounded-full shadow cursor-pointer text-gray-500 hover:text-red-500">
        <FaHeart size={16} />
      </div>

      {/* Product Image */}
      <img src={image} alt={title} className="w-full h-60 object-cover" />

      {/* Product Content */}
      <div className="p-4">
        <h4 className="text-sm font-semibold text-gray-600">3D Model</h4>
        <p className="text-gray-900 font-medium">{title}</p>
        <div className="flex items-center space-x-2 mt-2">
          <span className="text-[#006483] font-semibold">Rs.{price}</span>
          {oldPrice && (
            <span className="line-through text-gray-400 text-sm">Rs.{oldPrice}</span>
          )}
          {discount && (
            <span className="text-sm text-[#006483] font-semibold">({discount})</span>
          )}
        </div>
        <p className="text-gray-400 text-xs mt-1">max, obj, fbx, 3ds, lwo and more</p>
      </div>
    </div>
  );
}

