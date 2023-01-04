
export default class Utils {
  static replaceToken(text, tokens = []) {
    // const re = /{([^}]+)}/g; // match anything but a `}` between braces
    const re = /{[\w]*\}/g; // match initial regex

    let result = text;
    let textTokens = text.match(re);

    textTokens && textTokens.forEach(m => {
      let token = m.replace(/{|}/g, '');
      let replacement = tokens[token];
      result = result.replace(m, replacement);
    });

    return result;
  }
}
