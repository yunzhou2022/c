
function sleep(ms){
  return new Promise((res, rej)=>{
    setTimeout(res, ms);
  })
}

async function deleteOne(){
document.querySelector(".icon-background.bitable-layout-row.bitable-layout-cross-center").click();
  await sleep(300);
document.querySelector(".ud__menu").lastChild.click();
  await sleep(300);
document.querySelector(".ud__confirm__footer__btns").firstChild.click();
}

