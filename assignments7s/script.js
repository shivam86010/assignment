const API_URL = "https://interveiw-mock-api.vercel.app/api/getProducts";
const productContainer = document.getElementById("productContainer");
let products = [];

// with the help of fetch method call the api to feth the data and display the product in user interface 
fetch(API_URL)
  .then(response => response.json())
  .then(data => {
    if (data.status === "success" && data.data.length > 0) {
      products = data.data.map(item => item.product);
      displayProducts(products);
    } else {
      productContainer.innerHTML = "<p>No products available</p>";
    }
  })
  //if any error will be occure to fetch the data from api tha this part of code will be handle the error
  .catch(error => {
    console.error("Error fetching products:", error);
    productContainer.innerHTML = "<p>Failed to load products</p>";
  });

//use of this  function to display products on User interface 
function displayProducts(products) {
  productContainer.innerHTML = ""; 
  products.forEach(product => {
    const card = document.createElement("div");
    card.className = "card";
    
    //this is card content that display on each card(image , title, price )
    card.innerHTML = `
      <img src="${product.image.src}" alt="${product.title}">
          <div class="card-content">
            <div class="card-title">${product.title}</div>
            <div class="card-price">₹${product.variants[0].price}</div>
            <div class="card-vendor">Vendor: ${product.vendor}</div>
            <button class="card-button" onclick="addToCart(${product.id})">
              <img width="10" height="10" src="https://img.icons8.com/ios/50/FFFFFF/shopping-cart--v1.png" alt="shopping-cart--v1"/> Add to Cart
            </button>
          </div>
    `;
    productContainer.appendChild(card);
  });
}

// use of this function to handle add to cart button click 
//-or- alert method displays an alert box with a message and an OK button.
function addToCart(productId) {
  alert(`Product ID ${productId} added to cart!`);
}

// this function will be sort the product according to the price
function sortProductsbyprice(order) {
  if (order === "lowToHigh") {
    products.sort((a, b) => parseFloat(a.variants[0].price) - parseFloat(b.variants[0].price));
  } else if (order === "highToLow") {
    products.sort((a, b) => parseFloat(b.variants[0].price) - parseFloat(a.variants[0].price));
  }
  displayProducts(products);
}
