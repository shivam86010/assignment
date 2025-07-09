const Footer = () => {
    return (
      <footer className="bg-black text-white py-10 px-5 md:px-20">
        <div className="max-w-7xl mx-auto grid grid-cols-1 md:grid-cols-4 gap-8 text-center md:text-left">
          {/* About Section */}
          <div>
            <h3 className="text-lg font-semibold mb-3">About</h3>
            <p className="text-gray-400 text-sm">
              Far far away, behind the word mountains, far from the countries
              Vokalia and Consonantia, there live the blind texts.
            </p>
            <div className="flex justify-center md:justify-start gap-3 mt-4">
              <span className="bg-gray-800 p-2 rounded-full cursor-pointer">
                <i className="fab fa-twitter"></i>
              </span>
              <span className="bg-gray-800 p-2 rounded-full cursor-pointer">
                <i className="fab fa-facebook"></i>
              </span>
              <span className="bg-gray-800 p-2 rounded-full cursor-pointer">
                <i className="fab fa-instagram"></i>
              </span>
            </div>
          </div>
  
          {/* Links Section */}
          <div>
            <h3 className="text-lg font-semibold mb-3">Links</h3>
            <ul className="text-gray-400 text-sm space-y-2">
              <li>➝ Home</li>
              <li>➝ About</li>
              <li>➝ Services</li>
              <li>➝ Projects</li>
              <li>➝ Contact</li>
            </ul>
          </div>
  
          {/* Services Section */}
          <div>
            <h3 className="text-lg font-semibold mb-3">Services</h3>
            <ul className="text-gray-400 text-sm space-y-2">
              <li>➝ Web Design</li>
              <li>➝ Web Development</li>
              <li>➝ App Development</li>
              <li>➝ UI/UX Design</li>
            </ul>
          </div>
  
          {/* Contact Section */}
          <div>
            <h3 className="text-lg font-semibold mb-3">Have a Question?</h3>
            <p className="text-gray-400 text-sm flex items-center gap-2">
              <i className="fas fa-map-marker-alt"></i> Noida , Uttar Pradesh ,201309
            </p>
            <p className="text-gray-400 text-sm flex items-center gap-2 mt-2">
              <i className="fas fa-phone"></i> 8382044417
            </p>
            <p className="text-gray-400 text-sm flex items-center gap-2 mt-2">
              <i className="fas fa-envelope"></i> shivamsingh8601018@gmail.com
            </p>
          </div>
        </div>
        
        {/* Footer Bottom */}
        <div className="text-center text-gray-500 text-sm mt-10">
          Copyright &copy; 2025 All rights reserved by Shivam Singh
        </div>
      </footer>
    );
  };
  
  export default Footer;