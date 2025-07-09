import React from 'react';
import TextureBg from '../assets/Background.png';  // Your uploaded texture
import Illustration from '../assets/JoinCGTrader.png'; // Use the plane with characters image

export default function JoinCgt() {
  return (
   <section className="relative bg-[#006483] text-white">
  {/* Overlay to darken background */}
  <div className="absolute inset-0 bg-black bg-opacity-40 z-0" />

  {/* Content on top of overlay */}
  <div
    className="relative bg-cover bg-center"
    style={{
      backgroundImage: `url(${TextureBg})`,
    }}
  >
    <div className="max-w-7xl mx-auto px-4 py-20 flex flex-col lg:flex-row items-center justify-between relative z-10">
      {/* Text */}
      <div className="lg:w-1/2 text-white space-y-8">
        <h2 className="text-3xl md:text-4xl font-bold">
          Join Squarebagal <br /> Community
        </h2>

        <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
          <div>
            <h4 className="font-bold text-lg">Galleries</h4>
            <p className="text-sm">Showcase your best renders, get feedback and recognition</p>
          </div>
          <div>
            <h4 className="font-bold text-lg">Tutorials</h4>
            <p className="text-sm">Learn new skills and teach others</p>
          </div>
          <div>
            <h4 className="font-bold text-lg">Forum</h4>
            <p className="text-sm">Find tutorials and discuss other 3D related matters</p>
          </div>
        </div>

        <button className="mt-4 bg-white text-teal-600 font-medium px-6 py-2 rounded-full hover:bg-gray-100 transition">
          Join The Community
        </button>
      </div>

      {/* Image */}
      <div className="lg:w-1/2 mt-10 lg:mt-0 flex justify-center">
        <img
          src={Illustration}
          alt="Community Illustration"
          className="w-full max-w-md lg:max-w-lg object-contain"
        />
      </div>
    </div>
  </div>
</section>

  );
}
