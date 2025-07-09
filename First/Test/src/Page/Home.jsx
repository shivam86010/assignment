import React, { useRef } from "react";
import BgHomepage1 from '../assets/HomePageImage/Group1.png'
import BgHomepage2 from '../assets/HomePageImage/Group2.png'
import BgHomepage3 from '../assets/HomePageImage/Group3.png'
import BgHomepage4 from '../assets/HomePageImage/Group4.png'
// import BgHomepage5 from '../assets/HomePageImage/Group5.png'
import BgHomepage6 from '../assets/HomePageImage/Group6.png'
import BgHomepage7 from '../assets/HomePageImage/Group7.png'
import BgHomepage8 from '../assets/HomePageImage/Group8.png'
import BgHomepage9 from '../assets/HomePageImage/Group9.png'
import BgHomepage10 from '../assets/HomePageImage/Group61.png'
import Home from '../assets/Home.png'
import Cart from '../assets/HomePageImage/Cart.png'
import DonutImage from '../assets/Group 2.png';
import { FiSearch } from 'react-icons/fi';

import Bg from "../Components/bg/bg"

import "./Home.css"


const categories = [
  { name: "Aircraft", icon: BgHomepage1 },
  { name: "Car", icon: BgHomepage2 },
  { name: "Architectural", icon: BgHomepage3 },
  { name: "Exterior", icon: BgHomepage4 },
  { name: " Food", icon: BgHomepage6     },
  { name: " Interior", icon: BgHomepage7 },
  { name: "Industrial", icon: BgHomepage8 },
  { name: "Animal", icon: BgHomepage9 },
  { name: " Character", icon: BgHomepage10 },
];


export default function HomePage() {

      const scrollRef = useRef();

  const scrollLeft = () => {
    scrollRef.current.scrollBy({ left: -200, behavior: "smooth" });
  };

  const scrollRight = () => {
    scrollRef.current.scrollBy({ left: 200, behavior: "smooth" });
  };

  return (
    <div className="min-h-screen w-full font-sans bg-white">
      {/* Header */}
      <header className="flex items-center justify-between px-4 py-3 border-b">
        <div className="flex items-center gap-2">
          <img src={DonutImage} alt="logo" className="h-8 w-8" />
          <span className="text-lg text-[#038D96] font-bold">squarebagel</span>
        </div>
        <div className="relative w-full max-w-5xl">
            <input
              type="text"
              placeholder="Search 3D Models, Projects..."
              className="w-full px-4 py-2 pr-10 border rounded-3xl"
            />
            <FiSearch className="absolute right-3 top-1/2 transform -translate-y-1/2 h-5 w-5 text-gray-500" />
        </div>
        <div className="flex items-center gap-4">
          <button className="bg-[#038D96] text-white px-4 py-2 rounded-full hover:bg-teal-600">
            Share your work
          </button>
          <button className="text-sm">Login</button>
          <button>
            <img src={Cart} alt="cart" className="h-5 w-5" />
          </button>
        </div>
      </header>

      <div>
        {/* test */}

        <div>
          {/* Navigation Menu */}
          <section className="flex justify-center gap-8 py-3 text-sm font-medium mt-3 border-t overflow-x-auto whitespace-nowrap px-4 bg-white z-10 relative shadow">
            <div>Freelance 3D Projects ▾</div>
            <div>Sell 3D Models ▾</div>
            <div>Custom 3D Modeling ▾</div>
            <div>For Designers ▾</div>
          </section>

          {/* Hero Banner - overlaps upward under navbar */}
          <section className="relative text-white text-center  -mt-16 z-0">
            {/* Background SVG */}
            <div>
              <Bg />
            </div>

            {/* Category Icons - now directly below Hero */}
            <div className="w-full px-4 z-20 mt-[-40px] relative">
              <section className="mx-auto max-w-6xl bg-white shadow-md rounded-xl py-4 px-4 flex items-center gap-4">
                <button
                  onClick={scrollLeft}
                  className="text-black bg-gray-200 hover:bg-gray-300 rounded-full p-2 z-10"
                >
                  &lt;
                </button>

                <div
                  ref={scrollRef}
                  className="flex overflow-x-auto gap-6 px-2 w-full scrollbar-hide"
                >
                  {categories.map((cat, index) => (
                    <div
                      key={index}
                      className="flex-shrink-0 flex flex-col items-center text-sm text-gray-700 hover:text-teal-600 w-24 md:w-28 cursor-pointer transition"
                    >
                      <img src={cat.icon} alt={cat.name} className="w-12 h-12 mb-1" />
                      <span className="text-xs text-center">{cat.name}</span>
                    </div>
                  ))}
                </div>

                <button
                  onClick={scrollRight}
                  className="text-black bg-gray-200 hover:bg-gray-300 rounded-full p-2 z-10"
                >
                  &gt;
                </button>
              </section>
            </div>
          </section>
        </div>

      </div>

{/* Home Section */}

<div className="px-4 py-16 flex flex-col gap-10 md:flex-row md:items-center md:justify-around md:gap-8">
  {/* Left Block (Heading + Paragraph + Button) */}
  <div className="md:max-w-md text-center md:text-left space-y-4 order-1 md:order-none">
    <h2 className="text-2xl md:text-3xl font-semibold leading-snug">
      Looking For Custom <br className="hidden md:block" />
      3D Modeling at <br className="hidden md:block" />
      Scale
    </h2>
   
    <button className="bg-[#038D96] text-white px-6 py-2 rounded-full hover:bg-teal-600 transition duration-300">
      Get Started Here
    </button>
  </div>

  {/* Center Image */}
  <div className="flex justify-center order-3 md:order-none">
    <img src={Home} alt="home icon" className="w-48 md:w-64 h-auto object-contain" />
  </div>

  {/* Right Paragraph */}
  <div className="md:max-w-sm text-center md:text-left order-2 md:order-none">
    <p className="text-gray-600 text-base">
      Lorem ipsum, dolor sit amet consectetur adipisicing elit. Itaque, eum. Nulla reiciendis quod voluptas laboriosam, repudiandae sequi ex debitis ratione corrupti, explicabo.
    </p>
  </div>
</div>


    </div>
  );
}
