import React from "react";
import PlaneImage from '../assets/Aircraft.png'; // Update with actual path

export default function AirPlane() {
  return (
    <section className="bg-white px-4 py-16">
      <div className="max-w-7xl mx-auto flex flex-col lg:flex-row items-center gap-12">
        {/* Left Image */}
        <div className="w-full lg:w-1/2 flex justify-center">
          <img
            src={PlaneImage}
            alt="Plane character"
            className="w-[300px] md:w-[400px] lg:w-[500px] object-contain"
          />
        </div>

        {/* Right Content */}
        <div className="w-full lg:w-1/2">
          <h2 className="text-2xl md:text-3xl lg:text-4xl font-bold text-gray-900 mb-8">
            Sell your 3D Models <br className="hidden md:block" />
            and Find Freelance Projects
          </h2>

          <div className="grid grid-cols-1 sm:grid-cols-2 gap-x-8 gap-y-6 text-gray-700 text-sm">
            <div>
              <p className="mb-1 font-medium">Sell your 3D models and earn up to 80% royalties</p>
              <a href="#" className="text-teal-600 underline">Sell 3D Models</a>
            </div>
            <div>
              <p className="mb-1 font-medium">Outsource your skills & get up to 95% royalties</p>
              <a href="#" className="text-teal-600 underline">Browse Jobs</a>
            </div>
            <div>
              <p className="mb-1 font-medium">Work with enterprise clients</p>
              <a href="#" className="text-teal-600 underline">Get Qualified</a>
            </div>
            <div>
              <p className="mb-1 font-medium">Build your portfolio and be visible</p>
              <a href="#" className="text-teal-600 underline">Browse Designers</a>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
}
