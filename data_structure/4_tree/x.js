window.onload = () => {
  const array = Array.from(document.querySelector(".task-list").children);
  let pre = null, isAllRead = true;
  for (const x of array) {
    if (x.classList.contains("bg-gray-lighter")) {
      if (pre && isAllRead) {
        pre.click();
      }
      pre = x;
      isAllRead = true;
    }
    else if (x.children?.[0]?.classList.contains?.("es-icon-undone-check")) {
      isAllRead = false;
    }
  }
}
