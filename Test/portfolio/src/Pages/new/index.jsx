import React, { useEffect, useState } from "react";
// import { Helmet } from "react-helmet-async";
// import { useNavigate } from "react-router-dom";
// import CountUp from '../../Components/Card/CountUp';
// import Carousel from '../../Components/Carousel/index';
import Features from "./Features";
import Footer from "./Footer";
import HowItWorks from "./HowItWorks";
import TestCategories from "./TestCategories";
import { ArrowRight, Play, Star, Trophy, Users, Zap } from "lucide-react";
import SuccessStory from "./SuccessStory";
import About from './About'

export default function HomePage() {
  // const navigate = useNavigate();
  const [isSticky, setIsSticky] = useState(false);

  useEffect(() => {
    const handleScroll = () => {
      setIsSticky(window.scrollY > 100);
    };

    window.addEventListener("scroll", handleScroll);
    return () => window.removeEventListener("scroll", handleScroll);
  }, []);

  // const handleLoginClick = () => {
  //   navigate("/candidatelogin");
  // };

  // const handleAdminClick = () => {
  //   navigate("/adminLogin");
  // };

  return (
    <div className="min-h-screen bg-black text-white transition-colors duration-300">
      {/* <Helmet>
        <title>GaloScore | Online Test Portal</title>
        <meta name="description" content="GaloScore is a free online test portal for students to practice subject-wise tests, get instant results, and track performance without sign-up." />
        <meta name="keywords" content="online test, student exams, GaloScore, free practice test, instant results" />
        <meta name="author" content="GaloScore Team" />
        <meta property="og:title" content="GaloScore - Free Online Test Portal for Students" />
        <meta property="og:description" content="Take tests, get instant results and track your performance!" />
        <meta property="og:image" content="/pwa-512x512.png" />
        <meta property="og:type" content="website" />
      </Helmet> */}

      <header className={`${isSticky ? "sticky top-0 z-50 shadow-sm" : ""} flex items-center justify-between px-4 py-4 md:px-6 md:py-6 bg-black text-white transition-all duration-300`}>
        <div className="text-xl sm:text-2xl md:text-3xl font-bold text-yellow-400 tracking-tight">
          GaloScore
        </div>
        <nav className="hidden lg:flex gap-6 font-medium">
          <a href="#features" className="hover:text-yellow-400 transition">Features</a>
          <a href="#test" className="hover:text-yellow-400 transition">Take a Test</a>
          <a href="#Home" className="hover:text-yellow-400 transition">View Results</a>
        </nav>
        <div className="flex items-center gap-2 sm:gap-3">
          <button  className="text-sm sm:text-base border border-yellow-400 text-yellow-400 px-3 sm:px-4 py-2 rounded-lg hover:bg-yellow-500 hover:text-black transition">
            Login
          </button>
          <button  className="text-sm sm:text-base bg-yellow-500 text-black px-3 sm:px-4 py-2 rounded-lg hover:bg-yellow-400 transition">
            Admin Login
          </button>
        </div>
      </header>

      {/* Hero Section */}
      <section className="bg-black min-h-screen flex items-center relative overflow-hidden">
        <div className="absolute inset-0 opacity-20">
          <div className="absolute top-20 left-20 w-40 h-40 bg-yellow-400 rounded-full blur-3xl"></div>
          <div className="absolute bottom-20 right-20 w-52 h-52 bg-yellow-300 rounded-full blur-3xl"></div>
        </div>

        <div className="container mx-auto px-4 py-20 relative">
          <div className="grid lg:grid-cols-2 gap-16 items-center">
            <div className="text-center lg:text-left">
              <div className="inline-flex items-center bg-white/10 backdrop-blur-lg px-6 py-3 rounded-full mb-8 border border-white/20">
                <Trophy className="h-5 w-5 text-yellow-400 mr-2" />
                <span className="text-white font-medium">🎯 #1 Career Galo Score Platform</span>
              </div>
              <h1 className="text-6xl lg:text-7xl font-bold text-white mb-8 leading-tight">
                Unlock Your
                <span className="text-transparent bg-clip-text bg-gradient-to-r from-yellow-400 to-orange-500 block">
                  Dream Career
                </span>
              </h1>
              <p className="text-xl text-gray-300 mb-10 leading-relaxed max-w-2xl">
                Master professional assessments with AI-powered practice tests. Join 500,0+ students who've accelerated their careers through our comprehensive testing platform.
              </p>
              <div className="flex flex-col sm:flex-row gap-6 mb-12">
                <button className="inline-flex items-center justify-center rounded-full font-bold transition-colors bg-gradient-to-r from-yellow-400 to-orange-500 hover:from-yellow-500 hover:to-orange-600 text-black px-10 py-4 text-lg shadow-2xl hover:shadow-yellow-500/25">
                  <Play className="mr-3 h-6 w-6" />
                  Start Free Assessment
                </button>
                <button className="inline-flex items-center justify-center rounded-full border-2 border-white/30 text-white hover:bg-white/10 backdrop-blur-lg px-10 py-4 text-lg">
                  Watch Demo
                  <ArrowRight className="ml-3 h-5 w-5" />
                </button>
              </div>
              <div className="grid grid-cols-3 gap-8 text-center">
                <div>
                  <div className="text-4xl font-bold text-white mb-2">5K+</div>
                  <div className="text-gray-400">Active Users</div>
                </div>
                <div>
                  <div className="text-4xl font-bold text-white mb-2">98%</div>
                  <div className="text-gray-400">Success Rate</div>
                </div>
                <div>
                  <div className="text-4xl font-bold text-white mb-2">50+</div>
                  <div className="text-gray-400">Companies</div>
                </div>
              </div>
            </div>

            <div className="relative">
              <div className="rounded-lg border bg-white/10 text-white shadow-sm backdrop-blur-xl border-white/20 p-8">
                <div className="flex items-center mb-6">
                  <div className="bg-gradient-to-r from-yellow-400 to-orange-500 p-3 rounded-lg mr-4">
                    <Zap className="h-6 w-6 text-black" />
                  </div>
                  <div>
                    <h3 className="font-bold text-lg text-white">Assessment</h3>
                    <p className="text-gray-300">Personalized for your career</p>
                  </div>
                </div>

                <div className="p-6 pt-0 space-y-4 mb-6">
                  {[
                    {
                      label: "Cognitive Skills",
                      value: 85,
                      color: "from-green-400 to-blue-500",
                      width: "w-16",
                      text: "text-green-400"
                    },
                    {
                      label: "Technical Knowledge",
                      value: 78,
                      color: "from-yellow-400 to-orange-500",
                      width: "w-14",
                      text: "text-yellow-400"
                    },
                    {
                      label: "Communication",
                      value: 92,
                      color: "from-purple-400 to-pink-500",
                      width: "w-18",
                      text: "text-purple-400"
                    }
                  ].map((item, i) => (
                    <div key={i} className="flex justify-between items-center p-4 bg-white/5 rounded-lg border border-white/10">
                      <span className="text-white">{item.label}</span>
                      <div className="flex items-center">
                        <div className="w-20 h-2 bg-gray-600 rounded-full mr-3">
                          <div className={`h-2 ${item.width} bg-gradient-to-r ${item.color} rounded-full`} />
                        </div>
                        <span className={`${item.text} font-medium`}>{item.value}%</span>
                      </div>
                    </div>
                  ))}
                </div>

                <button className="w-full bg-gradient-to-r from-yellow-400 to-orange-500 hover:from-yellow-500 hover:to-orange-600 text-black font-bold py-3 rounded-lg inline-flex items-center justify-center">
                  Continue Assessment
                  <ArrowRight className="ml-2 h-5 w-5" />
                </button>
              </div>

              <div className="absolute -top-6 -right-6 bg-gradient-to-r from-yellow-400 to-yellow-300 p-4 rounded-full shadow-xl">
                <Star className="h-6 w-6 text-white" />
              </div>
              <div className="absolute -bottom-6 -left-6 bg-gradient-to-r from-yellow-400 to-yellow-300 p-4 rounded-full shadow-xl">
                <Users className="h-6 w-6 text-white" />
              </div>
            </div>
          </div>
        </div>
      </section>

      {/* <Carousel /> */}
      <TestCategories />
      {/* <CountUp /> */}
      <HowItWorks />
      <section id="features">
        <Features />
      </section>
      <SuccessStory />
      <About />
      <Footer />
    </div>
  );
}


// // import React, { useRef, useState } from "react";
// // import { FaQuoteLeft } from "react-icons/fa";

// // const testimonials = [
// //   {
// //     quote: "Creative geniuses who listen, understand, and craft captivating visuals - an agency that truly understands our needs.",
// //     name: "Gabrielle Williams",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// //   {
// //     quote: "Exceeded our expectations with innovative designs that brought our vision to life - a truly remarkable creative agency.",
// //     name: "Samantha Johnson",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// //   {
// //     quote: "Their ability to capture our brand essence in every project is unparalleled - an invaluable creative collaborator.",
// //     name: "Isabella Rodriguez",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// //   {
// //     quote: "Their team's artistic flair and strategic approach resulted in remarkable campaigns - a reliable creative partner.",
// //     name: "John Peter",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// //   {
// //     quote: "From concept to execution, their creativity knows no bounds - a game-changer for our brand’s success.",
// //     name: "Natalie Martinez",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// //   {
// //     quote: "A refreshing and imaginative agency that consistently delivers exceptional results - highly recommended for any project.",
// //     name: "Victoria Thompson",
// //     title: "CEO and Co-founder of ABC Company",
// //   },
// // ];

// // const TestimonialSection = () => {
// //   const containerRef = useRef(null);
// //   const [paused, setPaused] = useState(false);

// //   const handleCardClick = () => {
// //     setPaused(prev => !prev);
// //   };

// //   return (
// //     <section className="py-20 bg-white overflow-hidden">
// //       <h2 className="text-3xl md:text-4xl font-bold text-center mb-12 text-gray-900">
// //         Words of praise from others <br /> about our presence.
// //       </h2>

// //       <div
// //         ref={containerRef}
// //         className={`flex gap-6 animate-scroll transition-all duration-700 ${paused ? "paused" : ""}`}
// //       >
// //         {[...testimonials, ...testimonials].map((item, index) => (
// //           <div
// //             key={index}
// //             onClick={handleCardClick}
// //             className="min-w-[320px] max-w-sm bg-gray-50 border border-gray-200 p-6 rounded-xl shadow-md cursor-pointer hover:shadow-lg transition duration-300"
// //           >
// //             <FaQuoteLeft className="text-blue-500 mb-4" />
// //             <p className="text-gray-700 text-sm mb-4 leading-relaxed break-words whitespace-normal">
// //               {item.quote}
// //             </p>
// //             <div className="mt-auto">
// //               <p className="font-semibold text-gray-900">{item.name}</p>
// //               <p className="text-xs text-gray-500">{item.title}</p>
// //             </div>
// //           </div>
// //         ))}
// //       </div>

// //       {/* Animation Styles */}
// //       <style>{`
// //         .animate-scroll {
// //           animation: scrollLinear 40s linear infinite;
// //         }

// //         .paused {
// //           animation-play-state: paused;
// //         }

// //         @keyframes scrollLinear {
// //           0% { transform: translateX(0); }
// //           100% { transform: translateX(-50%); }
// //         }
// //       `}</style>
// //     </section>
// //   );
// // };

// // export default TestimonialSection;

// import React, { useRef, useState } from "react";
// import { FaQuoteLeft } from "react-icons/fa";

// const testimonials = [
//   {
//     quote: "Creative geniuses who listen, understand, and craft captivating visuals - an agency that truly understands our needs.",
//     name: "Gabrielle Williams",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=1"
//   },
//   {
//     quote: "Exceeded our expectations with innovative designs that brought our vision to life - a truly remarkable creative agency.",
//     name: "Samantha Johnson",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=2"
//   },
//   {
//     quote: "Their ability to capture our brand essence in every project is unparalleled - an invaluable creative collaborator.",
//     name: "Isabella Rodriguez",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=3"
//   },
//   {
//     quote: "Their team's artistic flair and strategic approach resulted in remarkable campaigns - a reliable creative partner.",
//     name: "John Peter",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=4"
//   },
//   {
//     quote: "From concept to execution, their creativity knows no bounds - a game-changer for our brand’s success.",
//     name: "Natalie Martinez",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=5"
//   },
//   {
//     quote: "A refreshing and imaginative agency that consistently delivers exceptional results - highly recommended for any project.",
//     name: "Victoria Thompson",
//     title: "CEO and Co-founder of ABC Company",
//     image: "https://i.pravatar.cc/100?img=6"
//   },
// ];

// const TestimonialSection = () => {
//   const containerRef = useRef(null);
//   const [paused, setPaused] = useState(false);

//   const handleCardClick = () => {
//     setPaused(prev => !prev);
//   };

//   return (
//     <section className="py-20 bg-white overflow-hidden">
//       <h2 className="text-3xl md:text-4xl font-bold text-center mb-12 text-gray-900">
//         Words of praise from others <br /> about our presence.
//       </h2>

//       <div
//         ref={containerRef}
//         className={`flex gap-6 animate-scroll transition-all duration-700 ${paused ? "paused" : ""}`}
//       >
//         {[...testimonials, ...testimonials].map((item, index) => (
//           <div
//             key={index}
//             onClick={handleCardClick}
//             className="min-w-[320px] max-w-sm bg-gray-50 border border-gray-200 p-6 rounded-xl shadow-md cursor-pointer hover:shadow-lg transition duration-300"
//           >
//             <FaQuoteLeft className="text-blue-500 mb-4" />
//             <p className="text-gray-700 text-sm mb-4 leading-relaxed line-clamp-2 break-words">
//               {item.quote}
//             </p>
//             <div className="mt-auto flex items-center gap-3">
//               <img
//                 src={item.image}
//                 alt={item.name}
//                 className="w-10 h-10 rounded-full object-cover"
//               />
//               <div>
//                 <p className="font-semibold text-gray-900">{item.name}</p>
//                 <p className="text-xs text-gray-500">{item.title}</p>
//               </div>
//             </div>
//           </div>
//         ))}
//       </div>

//       {/* Animation and clamp styles */}
//       <style>{`
//         .animate-scroll {
//           animation: scrollLinear 40s linear infinite;
//         }
//         .paused {
//           animation-play-state: paused;
//         }
//         @keyframes scrollLinear {
//           0% { transform: translateX(0); }
//           100% { transform: translateX(-50%); }
//         }
//       `}</style>
//     </section>
//   );
// };

// export default TestimonialSection;












