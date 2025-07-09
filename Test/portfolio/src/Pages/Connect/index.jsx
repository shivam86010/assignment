
import BackgroundImage from '../../assets/bg-image.jpg'

const ContactForm = () => {
    return (
      <div className="bg-black min-h-screen flex items-center justify-center px-5 md:px-20">
        <div className="relative max-w-6xl w-full grid grid-cols-1 md:grid-cols-2 items-center gap-10">
          {/* Left Section - Contact Form */}
          <div className="text-white">
            <h2 className="text-3xl md:text-4xl font-bold mb-4">
              Let's <span className="text-yellow-500">talk</span>
            </h2>
            <p className="text-gray-400 mb-6">
              To request a quote or meet up for work, contact me directly or fill out the form below.
            </p>
            
            <form className="space-y-4">
              <input type="text" placeholder="Your Name" className="w-full p-3 bg-gray-800 rounded-lg focus:outline-none text-white" />
              <input type="email" placeholder="Your Email" className="w-full p-3 bg-gray-800 rounded-lg focus:outline-none text-white" />
              <textarea placeholder="Your Message" className="w-full p-3 h-32 bg-gray-800 rounded-lg focus:outline-none text-white"></textarea>
              <button className="bg-yellow-500 text-black px-5 py-3 rounded-lg font-semibold drop-shadow-[2px_2px_2px_rgba(0,0,0,0.6)]">SEND MESSAGE</button>
            </form>
          </div>
  
          {/* Right Section - Image */}
          <div className="relative hidden md:block">
            <img src={BackgroundImage} alt="Woman with Phone" className="w-full rounded-lg" />
            <div className="absolute top-0 left-0 w-full h-full bg-yellow-500 opacity-30 rounded-lg"></div>
          </div>
        </div>
        
        {/* Sidebar Navigation */}
        <div className="absolute left-5 top-1/2 transform -translate-y-1/2 space-y-4 hidden md:block">
          <div className="bg-gray-800 p-3 rounded-full cursor-pointer">
            <i className="fas fa-home text-white"></i>
          </div>
          <div className="bg-gray-800 p-3 rounded-full cursor-pointer">
            <i className="fas fa-envelope text-white"></i>
          </div>
          <div className="bg-gray-800 p-3 rounded-full cursor-pointer">
            <i className="fas fa-info text-white"></i>
          </div>
        </div>
  
        {/* Social Media Icons */}
        <div className="absolute top-5 right-5 flex space-x-4">
          <i className="fab fa-facebook text-white cursor-pointer"></i>
          <i className="fab fa-instagram text-white cursor-pointer"></i>
          <i className="fab fa-linkedin text-white cursor-pointer"></i>
          <i className="fab fa-behance text-white cursor-pointer"></i>
        </div>
      </div>
    );
  };
  
  export default ContactForm;