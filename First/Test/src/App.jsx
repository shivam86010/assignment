import React from 'react'
import ModelMarketplace from './Components/ModelMarket'
import Footer from './Components/Footer'
import AirPlane from './Components/Airplane'
import JoinCgt from './Components/JoinCgt'
import AircraftPage from './Page/AircraftPage'
import HomePage from './Page/Home'

function App() {
  return (
    <div>
      <HomePage />
      <ModelMarketplace />
      <AirPlane />
      <JoinCgt />
      <AircraftPage />
      <Footer />
    </div>
  )
}

export default App
