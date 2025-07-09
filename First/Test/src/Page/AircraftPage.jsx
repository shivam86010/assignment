import React from "react";
import ProductCard from "../Components/ProductCard";
import img1 from "../assets/Airplane1.png"; 
import img2 from "../assets/Airplane2.png";
import img3 from "../assets/Airplane3.png";
import img4 from "../assets/Airplane4.png";
import Spiner from '../assets/Spiner.png';


export default function AircraftPage() {
  return (
    <div className="bg-[#F4F4F4] min-h-screen">
      {/* Header */}
      <div className="px-4 py-8 max-w-7xl mx-auto">
        <nav className="text-sm text-gray-500 mb-4">
          Home &gt; Freelance 3D Projects &gt; <span className="text-gray-900 font-medium">Aircraft 3D model</span>
        </nav>

        <div className="max-w-4xl mx-auto text-center px-4 py-10">
        <h1 className="text-3xl font-bold text-gray-900">Aircraft 3D models</h1>
        <p className="text-gray-500 mt-1 text-sm">5,464 3d items</p>

  <p className="text-gray-600 mt-4 text-sm">
    24,471 aircraft 3D models are available for download on our marketplace. CG 
    <a href="#" className="text-[#006483] underline ml-1">airplanes</a> will fit into simulations, visualizations, advertisements and videos. 
    <a href="#" className="text-[#006483] underline ml-1">Drones</a> bodies and parts will delight fans of tiny flying vehicles.
  </p>
</div>

      </div>

      {/* Filters */}
      <div className="px-4 py-6 border-t border-b bg-white">
        <div className="max-w-7xl mx-auto flex flex-wrap gap-4 items-center justify-between">
          <div className="flex gap-3 flex-wrap">
            {["Formats", "Poly count", "License", "Select attribute"].map((item) => (
              <select key={item} className="border rounded-md px-4 py-2 text-sm text-gray-700">
                <option>{item}</option>
              </select>
            ))}
            {/* Price Range Slider */}
            <div className="flex items-center space-x-2">
              <span>Rs.16,250</span>
              <input type="range" min="16250" max="40830" className="w-32" />
              <span>Rs.40,830</span>
            </div>
          </div>

          <div>
            <select className="border rounded-md px-4 py-2 text-sm text-gray-700">
              <option>Sort By</option>
            </select>
          </div>
        </div>
      </div>

      {/* Tags */}
      <div className="px-4 py-4 max-w-7xl mx-auto flex flex-wrap gap-2">
        {["Concept", "Visual", "Design", "boeing 737", "aviation", "bombardier", "Spitfire"].map((tag) => (
          <span key={tag} className="bg-gray-100 text-gray-700 text-sm px-3 py-1 rounded-full cursor-pointer hover:bg-gray-200">
            {tag}
          </span>
        ))}
      </div>

      {/* Products Grid */}
      <div className="px-4 pb-16 max-w-7xl mx-auto grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-6">
        <ProductCard title="Spitfire MKV8" price="14,715" oldPrice="16,350" discount="10% Off" image={img1} />
        <ProductCard title="Boeing 737 Interior With Galley" price="16,850" image={img2} />
        <ProductCard title="Flight Suit U2 Pilot 3D Model" price="18,350" image={img3} />
        <ProductCard title="Flight Suit F35 Pilot 3D Model" price="14,350" image={img4} />
      </div>

     
     

<div className="flex justify-center py-8">
  <img
    src={Spiner} 
    alt="Loading..."
    className="w-8 h-8 animate-spin"
  />
</div>

    </div>
  );
}
