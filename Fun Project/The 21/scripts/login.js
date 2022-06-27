
function validate_username(){
    let username = document.querySelector("#uname").value;
    if(username == 'Intan') return true;
    else return false;
}

function validate_password(){
    let password = document.querySelector("#password").value;
    if(password == 'intan') return true;
    else return false;
}

function login(){
    let username = document.querySelector("#uname").value;
    if(!validate_username() || !validate_password()){
        document.querySelector(".error-box").innerHTML = "Username atau password salah!"
        return;
    } 

    document.querySelector(".error-box").innerHTML = "";
    sessionStorage.setItem("username",username);
    window.location.href = './scripts/index.html';
    return;
}