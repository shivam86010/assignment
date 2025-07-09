import React, { useState, useEffect, useRef } from "react";
import { Menu, X } from "lucide-react";

const Header = () => {
  const [text, setText] = useState("");
  const words = ["Designer", "Developer", "Freelancer"];
  const wordIndex = useRef(0);
  const charIndex = useRef(0);
  const isDeleting = useRef(false);
  const timeoutRef = useRef(null);
  const [menuOpen, setMenuOpen] = useState(false);

  useEffect(() => {
    const typeEffect = () => {
      const currentWord = words[wordIndex.current];
      const updatedText = currentWord.substring(0, charIndex.current);
      setText(updatedText);

      if (!isDeleting.current && charIndex.current < currentWord.length) {
        charIndex.current++;
      } else if (isDeleting.current && charIndex.current > 0) {
        charIndex.current--;
      } else {
        isDeleting.current = !isDeleting.current;
        if (!isDeleting.current) {
          wordIndex.current = (wordIndex.current + 1) % words.length;
        }
      }

      timeoutRef.current = setTimeout(typeEffect, isDeleting.current ? 100 : 200);
    };

    typeEffect();

    return () => clearTimeout(timeoutRef.current);
  }, []);

  return (
    <header>
      <nav  className="fixed w-full   bg-[#E9E8E6] bg-opacity-80 p-4  flex justify-between items-center px-8 z-50 drop-shadow-[2px_2px_2px_rgba(0,0,0,0.6)]">
        <h2 className="text-xl font-bold">Shivam</h2>
        <button
          className="md:hidden cursor-pointer"
          aria-label="Toggle menu"
          onClick={() => setMenuOpen(!menuOpen)}
        >
          {menuOpen ? <X size={30} /> : <Menu size={30} />}
        </button>
        {/* Desktop Menu */}
        <ul className="hidden md:flex space-x-6">
          {["Home", "About", "Services", "Portfolio", "Contact"].map((item) => (
            <li key={item} className="hover:text-gray-400 cursor-pointer relative group">
              {item}
              <span className="absolute bottom-0 left-0 w-0 h-0.5 bg-blue-400 transition-all duration-300 group-hover:w-full"></span>
            </li>
          ))}
        </ul>
      </nav>

      {/* Sidebar Menu for Mobile */}
      <div
        className={`fixed top-0 left-0 h-screen w-64 bg-white shadow-lg transform transition-transform duration-300 z-50 md:hidden ${
          menuOpen ? "translate-x-0" : "-translate-x-full"
        }`}
      >
        <div className="flex justify-between items-center p-4 border-b border-gray-300">
          <h2 className="text-xl font-bold">Shivam</h2>
          <X size={30} className="cursor-pointer" onClick={() => setMenuOpen(false)} />
        </div>
        <ul className="flex flex-col p-4 space-y-4 text-gray-700">
          {["Home", "About", "Services", "Portfolio", "Contact"].map((item) => (
            <li
              key={item}
              className="hover:bg-gray-300 p-2 rounded cursor-pointer"
              onClick={() => setMenuOpen(false)}
            >
              {item}
            </li>
          ))}
        </ul>
      </div>

      {/* Overlay for Mobile */}
      {menuOpen && (
        <div
          className="fixed top-0 left-0 w-full h-full bg-black bg-opacity-50 z-40 md:hidden"
          onClick={() => setMenuOpen(false)}
        ></div>
      )}

      <div className="relative w-full h-screen bg-[#E9E8E6] flex items-center justify-center text-center ">
        <div className="absolute top-0 left-0 w-full h-full bg-[#E9E8E6] bg-opacity-50 z-10"></div>
        <div
          className="z-20 perspective-[1000px] hover:scale-105 transition-transform duration-700"
        >
          <div className="transform-gpu hover:rotate-x-6 hover:rotate-y-6 transition-transform duration-700">
            <h1 className="text-5xl font-bold">I am Shivam Singh</h1>
            <p className="text-3xl mt-2">{text}|</p>
          </div>
        </div>
      </div>
    </header>
  );
};

export default Header; 