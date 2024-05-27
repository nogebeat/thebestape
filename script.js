const quotes = [
    { text: "En accord avec le passé, le présent et le futur, Nick est le meilleur APE jamais eu.", author: "Salem GNANDI" },
    { text: "Une source d'inspiration. La preuve vivante que l'on peut vivre pleinement toutes ses passions. Joyeux anniversaire Nick !", author: "Aurel ATIOUKPE" },
    { text: "Joyeux anniversaire !", author: "James GBETCHEDJI" },
];

function displayRandomQuote() {
    const quoteElement = document.getElementById('quote');
    const randomIndex = Math.floor(Math.random() * quotes.length);
    const quote = quotes[randomIndex];
    quoteElement.innerHTML = `"${quote.text}"<br><br>- ${quote.author}`;
}

setInterval(displayRandomQuote, 5000);

displayRandomQuote();
