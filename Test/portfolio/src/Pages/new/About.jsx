import React from 'react';

import { Target, Users, Award, Globe, Heart, Lightbulb } from 'lucide-react';
import subra from '../../assets/shubhra-mohanka.jpg'
import Gautom from '../../assets/gautam-mohanka.jpg'

const About = () => {
  const values = [
    {
      icon: Target,
      title: "Excellence",
      description: "We strive for the highest quality in everything we do, from our test content to user experience."
    },
    {
      icon: Heart,
      title: "Student-Centric",
      description: "Every decision we make is focused on helping students achieve their career dreams."
    },
    {
      icon: Lightbulb,
      title: "Innovation",
      description: "We continuously innovate our platform to provide cutting-edge assessment solutions."
    },
    {
      icon: Globe,
      title: "Accessibility",
      description: "Making quality education and career opportunities accessible to students everywhere."
    }
  ];

  const team = [
    {
      name: "Mr. Gautam Mohanka",
      role: "Founder & CEO",
      image: Gautom,
      description: "Former IIT alumnus with 15 years of experience in EdTech industry."
    },

    
    {
      name: "Shubhra Mohanka",
      role: "CTO",
      image: subra,
      description: "Technology leader with expertise in AI and machine learning applications."
    },
        {
      name: "Nidhi Mohanka",
      role: "Head of Content",
      image: "https://images.unsplash.com/photo-1494790108755-2616b612b786?ixlib=rb-4.0.3&auto=format&fit=crop&w=687&q=80",
      description: "PhD in Education with expertise in creating assessment methodologies."
    },
    {
      name: "Sneha Patel",
      role: "Head of Partnerships",
      image: "https://images.unsplash.com/photo-14387616810-6461ffad8d80?ixlib=rb-4.0.3&auto=format&fit=crop&w=1170&q=80",
      description: "Building bridges between students and top companies across India."
    }
  ];

  return (
    <div className="min-h-screen bg-black text-white">
   
      
      {/* Hero Section */}
      <section className="py-20 bg-gradient-to-r from-black via-gray-900 to-black relative overflow-hidden">
        <div className="absolute inset-0">
          <div className="absolute top-10 left-1/4 w-64 h-64 bg-[#F59E0B] rounded-full mix-blend-multiply filter blur-xl opacity-10 animate-float"></div>
          <div className="absolute bottom-10 right-1/4 w-80 h-80 bg-[#FBBF24] rounded-full mix-blend-multiply filter blur-xl opacity-10 animate-float" style={{animationDelay: '3s'}}></div>
        </div>
        
        <div className="relative max-w-7xl mx-auto px-6 text-center">
          <div className="animate-fade-in">
            <h1 className="text-5xl lg:text-7xl font-bold mb-6">
              About <span className="text-[#F59E0B]">Galo Score</span>
            </h1>
            <p className="text-xl lg:text-2xl text-gray-300 max-w-4xl mx-auto">
              Empowering students to unlock their potential and achieve their career aspirations through innovative assessment solutions
            </p>
          </div>
        </div>
      </section>

      {/* Mission Section */}
      <section className="py-20">
        <div className="max-w-7xl mx-auto px-6">
          <div className="grid grid-cols-1 lg:grid-cols-2 gap-16 items-center">
            <div className="animate-fade-in">
              <h2 className="text-4xl lg:text-5xl font-bold mb-6">
                Our <span className="text-[#F59E0B]">Mission</span>
              </h2>
              <p className="text-xl text-gray-300 leading-relaxed mb-8">
                At Galo Score, we believe that every student deserves the opportunity to showcase their true potential. 
                Our mission is to bridge the gap between talent and opportunity by providing comprehensive, 
                industry-standard assessment solutions that help students prepare for their dream careers.
              </p>
              <p className="text-lg text-gray-400 leading-relaxed">
                Since our inception, we have helped over 50,000 students land their dream jobs at top companies, 
                maintaining an impressive 95% success rate through our scientifically designed tests and personalized learning paths.
              </p>
            </div>
            <div className="animate-scale-in">
              <div className="bg-gradient-to-br from-[#F59E0B] to-[#D67706] rounded-2xl p-8 text-black">
                <div className="grid grid-cols-2 gap-6">
                  <div className="text-center">
                    <div className="text-4xl font-bold mb-2">5K+</div>
                    <div className="text-sm">Students Placed</div>
                  </div>
                  <div className="text-center">
                    <div className="text-4xl font-bold mb-2">95%</div>
                    <div className="text-sm">Success Rate</div>
                  </div>
                  <div className="text-center">
                    <div className="text-4xl font-bold mb-2">50+</div>
                    <div className="text-sm">Companies</div>
                  </div>  
                  <div className="text-center">
                    <div className="text-4xl font-bold mb-2">1K+</div>
                    <div className="text-sm">Certificates</div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>

      {/* Values Section */}
      <section className="py-20 bg-gray-900">
        <div className="max-w-7xl mx-auto px-6">
          <div className="text-center mb-16 animate-fade-in">
            <h2 className="text-4xl lg:text-5xl font-bold mb-6">
              Our <span className="text-[#F59E0B]">Values</span>
            </h2>
            <p className="text-xl text-gray-300">
              The principles that guide everything we do
            </p>
          </div>

          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
            {values.map((value, index) => (
              <div 
                key={index}
                className="text-center group animate-scale-in"
                // style={`{animationDelay: ${index * 0.1}s}`}
              >
                <div className="mb-6 inline-flex items-center justify-center w-20 h-20 bg-[rgba(245,158,11,0.1)] rounded-full group-hover:bg-[#F59E0B] transition-all duration-300 group-hover:scale-110">
                  <value.icon className="h-10 w-10 text-[#F59E0B] group-hover:text-black transition-colors duration-300" />
                </div>
                <h3 className="text-xl font-bold text-white mb-4">{value.title}</h3>
                <p className="text-gray-400 leading-relaxed">{value.description}</p>
              </div>
            ))}
          </div>
        </div>
      </section>

      {/* Team Section */}
      <section className="py-20">
        <div className="max-w-7xl mx-auto px-6">
          <div className="text-center mb-16 animate-fade-in">
            <h2 className="text-4xl lg:text-5xl font-bold mb-6">
              Meet Our <span className="text-[#F59E0B]">Team</span>
            </h2>
            <p className="text-xl text-gray-300">
              The passionate people behind Galo Score success
            </p>
          </div>

          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
            {team.map((member, index) => (
              <div 
                key={index}
                className="text-center group animate-scale-in"
                // style={`{animationDelay: ${index * 0.1}s}`}
              >
                <div className="mb-6">
                  <img 
                    src={member.image} 
                    alt={member.name}
                    className="w-32 h-32 rounded-full mx-auto object-cover border-4 border-gray-800 group-hover:border-[#F59E0B] transition-colors duration-300"
                  />
                </div>
                <h3 className="text-xl font-bold text-[#F59E0B] mb-2">{member.name}</h3>
                <p className="text-white font-semibold mb-3">{member.role}</p>
                <p className="text-gray-400 text-sm leading-relaxed">{member.description}</p>
              </div>
            ))}
          </div>
        </div>
      </section>

     
    </div>
  );
};

export default About;