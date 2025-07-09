// import React, { useState } from 'react';
// import { FaFacebookF, FaTwitter, FaInstagram, FaYoutube , FaChevronUp, FaChevronDown} from 'react-icons/fa';
// import DonutImage from '../assets/Group 2.png';

// export default function Footer() {
//   const [openSection, setOpenSection] = useState(null);

//   const toggleSection = (section) => {
//     setOpenSection(openSection === section ? null : section);
//   };

//   const isMobile = typeof window !== 'undefined' && window.innerWidth < 768;

//   const FooterSection = ({ title, items, id }) => (
//   <div className="text-white">
//     {/* Mobile Accordion Heading */}
//     <div
//       className="md:hidden cursor-pointer font-semibold mb-2 border-b border-gray-700 flex justify-between items-center py-2"
//       onClick={() => toggleSection(id)}
//     >
//       <span>{title}</span>
//       <span>
//         {openSection === id ? <FaChevronUp className="text-sm" /> : <FaChevronDown className="text-sm" />}
//       </span>
//     </div>

//     {/* Mobile List */}
//     {openSection === id && (
//       <ul className="md:hidden space-y-1 text-sm text-gray-300 mb-4">
//         {items.map((item, index) => (
//           <li key={index}>{item}</li>
//         ))}
//       </ul>
//     )}

//     {/* Desktop List */}
//     <div className="hidden md:block">
//       <h4 className="font-semibold mb-2 border-b border-gray-700 pb-2">{title}</h4>
//       <ul className="space-y-1 text-sm text-gray-300">
//         {items.map((item, index) => (
//           <li key={index}>{item}</li>
//         ))}
//       </ul>
//     </div>
//   </div>
// );

//   return (
//     <footer className="relative bg-[#393939] text-white px-4 py-12 overflow-hidden">
//       <div className="max-w-7xl mx-auto grid md:grid-cols-6 gap-12">
//         {/* Newsletter */}
//         <div className="md:col-span-2">
//           <h4 className="text-sm uppercase tracking-widest">Stay up to date</h4>
//           <h2 className="text-2xl font-bold mt-2 mb-4 leading-snug">
//             <div>get our</div>
//             <div>newsletter</div>
//           </h2>
//           <div className="max-w-xs">
//             <div className="flex items-center">
//               <input
//                 type="email"
//                 placeholder="Your email"
//                 className="bg-transparent text-white placeholder-white py-2 outline-none border-b border-white w-[200px]"
//               />
//               <button className="ml-2 bg-white text-gray-900 w-8 h-8 flex items-center justify-center rounded-full">
//                 →
//               </button>
//             </div>
//           </div>
//         </div>

//         {/* Accordion Sections */}
//         <FooterSection
//           title="Company"
//           id="company"
//           items={['Blog', 'Events', 'Press', 'Careers', 'Help Center', 'Contact Us']}
//         />
//         <FooterSection
//           title="Modelry"
//           id="modelry"
//           items={['3D Viewer', '3D Product' ,'Visualization', '3D Digital Asset', 'Management', 'Custom 3D', 'Modeling', 'Virtual', 'Photography']}
//         />
//         <FooterSection
//           title="Sell 3D Models"
//           id="sell"
//           items={['Community', '3D Designers', 'Forum', 'Freelance with us', 'Loyalty credits', 'Program']}
//         />
//         <FooterSection
//           title="Get in touch"
//           id="contact"
//           items={[
//             'hello@squarebagal.com',
//             '+91 8826688426',
//             <div key="social" className="mt-10 text-white text-sm space-y-2">
//             <h4 className="font-semibold">See what we're up to</h4>
//             <div className="flex space-x-4 text-lg">
//               <FaFacebookF />
//               <FaTwitter />
//               <FaInstagram />
//               <FaYoutube />
//             </div>
//           </div>

//           ]}
//         />
//       </div>

//       {/* Footer Bottom Section */}
//       <div className="  mt-12 pt-6 text-center text-sm text-gray-400">
//         <div className="flex flex-col md:flex-row justify-between items-center max-w-7xl mx-auto px-4">
//           <div className="flex items-center space-x-2">
//             <div className="bg-teal-500 text-white rounded-full px-2 py-1 font-bold">squarebagel</div>
//             <span>© Copyright squarebagel 2022</span>
//             <a href="#">Terms & Conditions</a>
//             <a href="#">Privacy Policy</a>
//           </div>
//         </div>
//       </div>

//       {/* Donut image at bottom right */}
//       <img
//         src={DonutImage}
//         alt="Donut"
//         className="absolute bottom-0 right-0 w-32 md:w-40 lg:w-52 pointer-events-none select-none"
//       />
//     </footer>
//   );
// }



import React, { useState } from 'react';
import {
  FaFacebookF,
  FaTwitter,
  FaInstagram,
  FaYoutube,
  FaChevronUp,
  FaChevronDown,
} from 'react-icons/fa';
import DonutImage from '../assets/Group 2.png';

export default function Footer() {
  const [openSection, setOpenSection] = useState(null);

  const toggleSection = (section) => {
    setOpenSection(openSection === section ? null : section);
  };

  const FooterSection = ({ title, items, id }) => (
    <div className="text-white">
      {/* Mobile Accordion Heading */}
      <div
        className="md:hidden cursor-pointer font-semibold mb-2 border-b border-gray-700 flex justify-between items-center py-2"
        onClick={() => toggleSection(id)}
      >
        <span>{title}</span>
        <span>
          {openSection === id ? (
            <FaChevronUp className="text-sm" />
          ) : (
            <FaChevronDown className="text-sm" />
          )}
        </span>
      </div>

      {/* Mobile List */}
      {openSection === id && (
        <ul className="md:hidden space-y-1 text-sm text-gray-300 mb-4">
          {items.map((item, index) => (
            <li key={index}>{item}</li>
          ))}
        </ul>
      )}

      {/* Desktop List */}
      <div className="hidden md:block">
        <h4 className="font-semibold mb-2 border-b border-gray-700 pb-2">{title}</h4>
        <ul className="space-y-1 text-sm text-gray-300">
          {items.map((item, index) => (
            <li key={index}>{item}</li>
          ))}
        </ul>
      </div>
    </div>
  );

  return (
    <footer className="relative bg-[#393939] text-white px-4 py-12 overflow-hidden">
      <div className="max-w-7xl mx-auto grid md:grid-cols-6 gap-12">
        {/* Newsletter */}
        <div className="md:col-span-2">
          <h4 className="text-sm uppercase tracking-widest">Stay up to date</h4>
          <h2 className="text-2xl font-bold mt-2 mb-4 leading-snug">
            <div>get our</div>
            <div>newsletter</div>
          </h2>
          <div className="max-w-xs">
            <div className="flex items-center">
              <input
                type="email"
                placeholder="Your email"
                className="bg-transparent text-white placeholder-white py-2 outline-none border-b border-white w-[200px]"
              />
              <button className="ml-2 bg-white text-gray-900 w-8 h-8 flex items-center justify-center rounded-full">
                →
              </button>
            </div>
          </div>
        </div>

        {/* Footer Sections */}
        <FooterSection
          title="Company"
          id="company"
          items={['Blog', 'Events', 'Press', 'Careers', 'Help Center', 'Contact Us']}
        />
        <FooterSection
          title="Modelry"
          id="modelry"
          items={[
            '3D Viewer',
            '3D Product',
            'Visualization',
            '3D Digital Asset',
            'Management',
            'Custom 3D',
            'Modeling',
            'Virtual',
            'Photography',
          ]}
        />
        <FooterSection
          title="Sell 3D Models"
          id="sell"
          items={[
            'Community',
            '3D Designers',
            'Forum',
            'Freelance with us',
            'Loyalty credits',
            'Program',
          ]}
        />
        <FooterSection
          title="Get in touch"
          id="contact"
          items={['hello@squarebagal.com', '+91 8826688426']}
        />
      </div>

      {/* Social Section (outside accordion) */}
      <div className="mt-10 text-white text-sm space-y-2 md:text-left max-w-7xl mx-auto">
        <h4 className="font-semibold">See what we're up to</h4>
        <div className="flex  md:justify-start space-x-4 text-lg">
          <FaFacebookF />
          <FaTwitter />
          <FaInstagram />
          <FaYoutube />
        </div>
      </div>

      {/* Footer Bottom Section */}
      <div className="mt-12 pt-6  text-sm text-gray-400">
        <div className="flex flex-col md:flex-row justify-between max-w-7xl mx-auto px-4 gap-4">
          {/* Donut Image or Brand */}
          <div className="flex items-center gap-2">
            <img
              src={DonutImage}
              alt="Donut Logo"
              className="w-6 h-6 md:w-8 md:h-8 object-contain"
            />
            <h1 className='md:text-lg md:font-semibold'>squarebagel</h1>
            
            <span className="hidden md:inline">© Copyright squarebagel 2022</span>
            <a className='hidden md:inline' href="#">Terms & Conditions</a>
            <a className='hidden md:inline' href="#">Privacy Policy</a>
          </div>
          <span className="md:hidden">© Copyright squarebagel 2022</span>

          {/* Policy Links - only on desktop */}
          <div className="hidden md:hidden md:flex space-x-4">
            <a href="#">Terms & Conditions</a>
            <a href="#">Privacy Policy</a>
          </div>
        </div>
      </div>

      {/* Donut image at bottom right */}
      <img
        src={DonutImage}
        alt="Donut"
        className="absolute bottom-0 right-0 w-32 md:w-40 lg:w-52 pointer-events-none select-none"
      />
    </footer>
  );
}


