const quotes = [
    { text: "En accord avec le passé, le présent et le futur, Nick est le meilleur APE jamais eu.", author: "Salem GNANDI" },
    { text: "Une source d'inspiration. La preuve vivante que l'on peut vivre pleinement toutes ses passions. Joyeux anniversaire Nick !", author: "Aurel ATIOUKPE" },
    { text: "Joyeux anniversaire, le hackeur le plus frais🔥🔥Bienvenue dans la vingtaine 💪🏾💪🏾", author: "Henok" },
    { text: "Le meilleur et plus de good vibes", author: "Roleo" },
    { text: "Joyeux anniversaire bro ❤😹 Tout le meilleur pour toi.", author: "Modeste" },
    { text: "Hbd. Garde toujours cette énegrie débordante qui te caractérise tant", author: "Mary Ange" },
    { text: "Joyeux anniversaire boss. N'arrête jamais de répandre ta joie de vivre autour de toi", author: "Soraya" },
    { text: "echo 'efeJ eiv eugnoL .setnannoissap setrevuocéd ed te sèccus ed eilpmer tios eénna ettec euQ .rûs sulp euqirémun ednom el erdner ed icreM' | rev", author: "Cephax"},
];

const quotes2 = [
    { text: "Hey King🤴, it's your day. Wanna to celebrate the amazing person 🤌❤that you are. Your positive influence and charisma illuminate our lives in a way that words struggle to describe. Today, I wish you all the happiness in the world and a year filled with success.✨ And maybe one day our paths will cross in an even more meaningful way, like a silent promise carried by destiny😉Happy birthday Nick, with all my affection and most sincere thoughts.", author: "Vicky🫂❤" },
    { text: "Chère Nick, Je tenais à prendre un moment pour te souhaiter un joyeux anniversaire ! En cette journée spéciale pour toi, je veux que tu saches à quel point tu comptes pour nous et combien nous sommes reconnaissant pour ton immense bienveillance. Je tiens aussi à te dire que nous n' aurions pas pu avoir un meilleur APE. Ta gentillesse, ton soutien et ta présence sont des cadeaux inestimables. J' espère que cette journée sera rempli de bonheur, d'amour et de surprises agréables. Que cette nouvelle année de ta vie soit encore plus merveilleuse que la précédente, et qu'elle t'apporte tout ce que tu désires. Cordialement,", author: "Le Badeur"},
    { text: "Salut à toi, programmeur intrépide,Aujourd'hui, c'est ton anniversaire, alors que dirais-tu d'une boucle infinie de joie et de gâteau ?Que tes pointeurs soient toujours valides, tes boucles toujours bien bouclées, et que tes bugs soient aussi rares que les commentaires dans du code hérité.Puisses-tu célébrer comme un processus en attente de signal, avec des pauses aussi courtes que des microsecondes et des festivités aussi joyeuses que des threads bien synchronisés.Joyeux anniversaire, ô maître du C ! Que ta journée soit aussi optimisée que du code en assembleur et que ta soirée soit plus fun que de déboguer un programme écrit par un stagiaire.", author: "Salem GNANDI"},
    { text: "T'as été un bon APE pour un, t'as su connaître nos douleurs et nos faiblesses, t'as su quand tout allait mal et tu n'es pas resté muet face à nos douleurs. T'as toujours su trouver de solution à nos problèmes et à nous rendre heureux. Nous sommes fiers de celà. C'est pourquoi je te remercie sincèrement pour ce guide exemplaire et fantastique que t'as été pour nous, et ce spécialement en ce jour ton anniversaire je te souhaite de toujours avoir ce bon coeur, Que Dieu Oluwa te guide et ton protège Durant tout ton parcours et qu'il soit ton refuge, ton aide, qu'il te fortifie, et surtout que tes passions pour tout comme pour la musique ne soient pas juste une pensé mais quelles deviennent réalité. T'as été le meilleure sur tout le parcours et tu resteras encore le meilleure. Je te souhaite un joyeux anniversaire, celui ci ne sera pas le dernier mais l'un des meilleurs pour toi. May God bless you", author: "Anne SEZAN"},
    { text: "Joyeux anniversaire Nick AKA le Hackeur. Que tous tes vœux se réalisent et que cette nouvelle année soit une année d’opportunités, de joie et de bonheur.", author: "Le Joker"},
];

function displayRandomQuote() {
    const quoteElement = document.getElementById('quote');
    const randomIndex = Math.floor(Math.random() * quotes.length);
    const quote = quotes[randomIndex];
    quoteElement.innerHTML = `"${quote.text}"<br><br>- ${quote.author}`;
}

function displayRandomQuote2() {
    const quoteElement = document.getElementById('quote2');
    const randomIndex = Math.floor(Math.random() * quotes2.length);
    const quote2 = quotes2[randomIndex];
    quoteElement.innerHTML = `"${quote2.text}"<br><br>- ${quote2.author}`;
}

setInterval(displayRandomQuote, 5000);

setInterval(displayRandomQuote2, 10000);

displayRandomQuote();

displayRandomQuote2();

