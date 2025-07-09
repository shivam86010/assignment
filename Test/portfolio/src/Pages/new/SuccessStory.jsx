import React from 'react';
import { FaStar } from 'react-icons/fa';

const testimonials = [
  {
    name: "Lena Morris",
    role: "Operations Consultant",
    image: "https://i.pravatar.cc/100?img=1",
    rating: 5,
    score: 99,
    feedback:
      "Their team brought fresh perspective to our operations and led our leadership team through impactful transformation.",
  },
  {
    name: "Kevin Brooks",
    role: "Financial Advisor",
    image: "https://i.pravatar.cc/100?img=2",
    rating: 5,
    score: 99,
    feedback:
      "Professional, thoughtful, and results-driven. The portal gave us tools that actually work — not just theories.",
  },
  {
    name: "Monica Evans",
    role: "Project Manager",
    image: "https://i.pravatar.cc/100?img=3",
    rating: 5,
    score: 99,
    feedback:
      "Using this platform was a game changer. We gained strategic clarity and saw immediate improvements in performance.",
  },
];

const SuccessStory = () => {
  return (
    <section className="py-32 bg-gradient-to-b from-slate-50 via-white to-slate-50 relative overflow-hidden">
      {/* Grid background */}
      <div className="absolute inset-0 bg-[linear-gradient(to_right,#8080800a_1px,transparent_1px),linear-gradient(to_bottom,#8080800a_1px,transparent_1px)] bg-[size:20px_20px]" />

      {/* Main Content */}
      <div className="relative max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center mb-16">
          <span className="inline-block bg-yellow-400 text-black text-xs font-bold px-4 py-1 rounded-full mb-4">
            Client Testimonials
          </span>
          <h2 className="text-4xl sm:text-5xl font-bold text-gray-900">
            Trusted by Professionals Who<br /> Value Real Impact
          </h2>
          <p className="text-lg text-gray-600 mt-4 max-w-3xl mx-auto">
            Hear what our clients have to say about working with our Test Portal. From strategy to execution,
            we've helped candidates turn challenges into success stories — and we're ready to do the same for you.
          </p>
        </div>

        {/* Avatars + Stats */}
        <div className="flex justify-center items-center gap-3 mb-12">
          <div className="flex -space-x-3">
            {[1, 2, 3, 4].map((i) => (
              <img
                key={i}
                src={`https://i.pravatar.cc/100?img=${i}`}
                className="w-10 h-10 rounded-full border-2 border-white shadow"
              />
            ))}
          </div>
          <span className="text-yellow-500 font-bold text-sm sm:text-base">
            4.6k Best Reviews<br />For Test Portal
          </span>
        </div>

        {/* Testimonial Cards */}
        <div className="grid gap-8 sm:grid-cols-2 lg:grid-cols-3">
          {testimonials.map((person, index) => (
            <div
              key={index}
              className="bg-white/80 backdrop-blur-md border border-gray-200 rounded-2xl p-6 shadow-xl relative hover:shadow-2xl transition-all duration-300"
            >
              {/* Rating Stars */}
              <div className="flex mb-3">
                {[...Array(5)].map((_, i) => (
                  <FaStar
                    key={i}
                    className={`h-4 w-4 ${i < person.rating ? 'text-yellow-400' : 'text-gray-300'}`}
                  />
                ))}
              </div>

              {/* Avatar + Info */}
              <div className="flex items-center gap-4 mb-3">
                <img
                  src={person.image}
                  alt={person.name}
                  className="w-12 h-12 rounded-full object-cover"
                />
                <div>
                  <h3 className="font-semibold text-gray-900">{person.name}</h3>
                  <p className="text-gray-500 text-sm">{person.role}</p>
                </div>
              </div>

              {/* Feedback */}
              <p className="text-gray-700 text-sm leading-relaxed">“{person.feedback}”</p>

              {/* Score */}
              <span className="absolute top-6 right-6 text-yellow-500 text-xl font-bold">
                {person.score}
              </span>
            </div>
          ))}
        </div>

        {/* Dots (optional pagination UI) */}
        <div className="mt-10 flex justify-center gap-2">
          <div className="w-3 h-3 rounded-full bg-yellow-500"></div>
          <div className="w-3 h-3 rounded-full bg-gray-400"></div>
          <div className="w-3 h-3 rounded-full bg-gray-400"></div>
        </div>
      </div>
    </section>
  );
};

export default SuccessStory;