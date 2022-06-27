
function direct_home(){
    window.location.href = 'index.html'
    return;
}

function main(){
    alert("Hello! Sebelum masuk ke Wish harus jawab beberapa pertanyaan dulu!")
    let username = null;
    while(true){
        username = prompt("Confirm your name, please!");
        if(username == null){
            direct_home();
            return -1;
        }
        if(username.toLowerCase() === "intan") break;
    }

    while(true){
        let password = prompt("Confirm your password, please!");
        if(username == null){
            direct_home();
            return -1;
        }
        if(password.toLowerCase() === "intan") break;
    }
    alert("Welcome " + username + "! get ready for the quiz!");
    
    while(true){
        let jadian = prompt("Tanggal berapa kita jadian? Format : dd/mm/yyyy ");
        if(jadian == null){
            direct_home();
            return -1;
        }
        if(jadian.toLowerCase() === "21/07/2016"){
            alert("Benar! Lanjut!");
            break;
        }
    }

    while(true){
        let jadian_age = prompt("Jadi udah berapa lama kita pacaran? (hanya angka) .. tahun");
        if(jadian_age == null){
            direct_home();
            return -1;
        }
        if(jadian_age.toLowerCase() === "5" || jadian_age.toLowerCase() === "5 tahun"){
            alert("Benar! Lanjut!");
            break;
        }
    }

    while(true){
        let ditembak = prompt("Ditembak lewat apa? (Game Pool/Messenger/Whatsapp)");
        if(ditembak == null){
            direct_home();
            return -1;
        }
        if(ditembak.toLowerCase() === "game pool"){
            alert("Benar! Lanjut!");
            break;
        }
    }

    while(true){
        let angka = prompt("Angka sakral kita apa?");
        if(angka == null){
            direct_home();
            return -1;
        }
        if(angka.toLowerCase() === "21"){
            alert("Benar! Ini wishnya sayangg");
            break;
        }
    }

}


main();