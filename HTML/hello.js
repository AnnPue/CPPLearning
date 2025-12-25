document.addEventListener('DOMContentLoaded', function() {
    document.querySelector('#usrname').focus(); // Set focus to the input field on page load
    const name = document.querySelector('p'); // 提前获取p标签，避免重复查询
    let input = document.querySelector('input');
    input.addEventListener('keyup', function() {
        if (input.value) {
            name.innerHTML = `Hello, ${input.value}. `;
        }
        else {
            name.innerHTML = 'Hello, bro. ';
        }
    });
});