import { defineConfig } from "astro/config";
import vercel from "@astrojs/vercel/static";
import svelte from "@astrojs/svelte";
import tailwind from "@astrojs/tailwind";
import remarkMermaid from "astro-diagram/remark-mermaid";
import prefetch from "@astrojs/prefetch";
import mdx from "@astrojs/mdx";

export default defineConfig({
    output: "static",
    adapter: vercel(),
    integrations: [svelte(), prefetch(), tailwind(), mdx()],
    markdown: {
        remarkPlugins: [remarkMermaid, "remark-math"],
        rehypePlugins: ["rehype-katex"]
    }
});
